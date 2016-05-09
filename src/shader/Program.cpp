#include "slim/containers/Buffer.hpp"
#include "slim/debug/assert.hpp"
#include "slim/memory/Manager.hpp"
#include "slim/graphics/glDebug.hpp"
#include "slim/shader/Program.hpp"

namespace slim
{
namespace shader
{

const char* const
Program::typeName = "shader program";


memory::ArenaChunk&
Program::getMemoryChunk()
{
    if (!s_memory.isInited())
    {
	s_memory.init(memory::Manager::instance.createChunk<memory::ArenaChunk>(SLIM_SHADER_PROGRAM_MEMORY_SIZE,
										"Shader uniforms"));
    }
    return s_memory.getData();
}

containers::SingleWrap<memory::ArenaChunk>
Program::s_memory;


Program::Program(const char* name, const Shader* vertexShader, const Shader* fragmentShader) :
    assets::Asset(Program::typeName, name),
    m_vertexShader(vertexShader),
    m_fragmentShader(fragmentShader),
    m_uniforms(Program::getMemoryChunk())
{
    SLIM_DEBUG_ASSERT(vertexShader->getType() == Shader::VERTEX);
    SLIM_DEBUG_ASSERT(fragmentShader->getType() == Shader::FRAGMENT);

    this->listen(vertexShader);
    this->listen(fragmentShader);
}

Program::~Program()
{
}


void
Program::setUniform(const char* name, bool value) const
{
    this->checkUniform(name);
    glUniform1i(m_uniforms[name], value);
    SLIM_GRAPHICS_GL_CHECK();
}

void
Program::setUniform(const char* name, int value) const
{
    this->checkUniform(name);
    glUniform1i(m_uniforms[name], value);
    SLIM_GRAPHICS_GL_CHECK();
}

void
Program::setUniform(const char* name, float value) const
{
    this->checkUniform(name);
    glUniform1f(m_uniforms[name], value);
    SLIM_GRAPHICS_GL_CHECK();
}

void
Program::setUniform(const char* name, const Vector2& value) const
{
    this->checkUniform(name);
    glUniform2f(m_uniforms[name], value.x, value.y);
    SLIM_GRAPHICS_GL_CHECK();
}

void
Program::setUniform(const char* name, const Vector3& value) const
{
    this->checkUniform(name);
    glUniform3f(m_uniforms[name], value.x, value.y, value.z);
    SLIM_GRAPHICS_GL_CHECK();
}

void
Program::setUniform(const char* name, const Vector4& value) const
{
    this->checkUniform(name);
    glUniform4f(m_uniforms[name], value.x, value.y, value.z, value.w);
    SLIM_GRAPHICS_GL_CHECK();
}

void
Program::setUniform(const char* name, const Matrix4x4& value) const
{
    this->checkUniform(name);
    glUniformMatrix4fv(m_uniforms[name], 1, false, value.asArray());
    SLIM_GRAPHICS_GL_CHECK();
}


void
Program::onAssetsReady()
{
    GLint	linked;

    SLIM_GRAPHICS_GL_ASSERT(m_id = glCreateProgram());

    glAttachShader(m_id, m_vertexShader->getId());
    glAttachShader(m_id, m_fragmentShader->getId());
    glLinkProgram(m_id);
    glDetachShader(m_id, m_vertexShader->getId());
    glDetachShader(m_id, m_fragmentShader->getId());

    glGetProgramiv(m_id, GL_LINK_STATUS, &linked);
    if (!linked)
    {
	char	error[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

	glGetProgramInfoLog(m_id, SLIM_DEBUG_MESSAGE_BUFFER_SIZE, nullptr, error);
	SLIM_DEBUG_EXIT("Error linking shader program: ", error);
    }
}

void
Program::onAssetsUnloaded()
{
    glDeleteProgram(m_id);
}


void
Program::addUniform(const char* name) const
{
    Uniform	uniform = glGetUniformLocation(m_id, name);

    if (uniform == -1)
    {
	SLIM_GRAPHICS_DEBUG_EXIT();
    }
    SLIM_GRAPHICS_GL_CHECK();
    m_uniforms.insert(name, uniform);
}

void
Program::checkUniform(const char* name) const
{
    if (!m_uniforms.containsKey(name))
    {
	this->addUniform(name);
    }
}

}
}
