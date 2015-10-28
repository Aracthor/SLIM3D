#include "slim/containers/Buffer.hpp"
#include "slim/debug/assert.hpp"
#include "slim/graphics/glDebug.hpp"
#include "slim/shader/Program.hpp"

namespace slim
{
namespace shader
{

const char* const
Program::typeName = "shader program";


Program::Program(const char* name, const Shader* vertexShader, const Shader* fragmentShader) :
    assets::Asset(Program::typeName, name),
    m_vertexShader(vertexShader),
    m_fragmentShader(vertexShader)
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
Program::onAssetsReady()
{
    GLint	linked;

    SLIM_GRAPHICS_GL_CHECK(m_id = glCreateProgram());

    glAttachShader(m_id, m_vertexShader->getId());
    glAttachShader(m_id, m_fragmentShader->getId());
    glLinkProgram(m_id);

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

}
}
