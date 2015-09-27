#include "slim/containers/Buffer.hh"
#include "slim/debug/assert.hh"
#include "slim/graphics/GLException.hh"
#include "slim/shader/Program.hh"
#include "slim/io/ResourceException.hh"

namespace slim
{
namespace shader
{

Program::Program(const char* name, const Shader& vertexShader, const Shader& fragmentShader) :
    m_name(name)
{
    GLint	linked;

    SLIM_DEBUG_ASSERT(vertexShader.getType() == Shader::VERTEX);
    SLIM_DEBUG_ASSERT(fragmentShader.getType() == Shader::FRAGMENT);

    SLIM_GRAPHICS_GL_CHECK(m_id = glCreateProgram());

    glAttachShader(m_id, vertexShader.getId());
    glAttachShader(m_id, fragmentShader.getId());
    glLinkProgram(m_id);

    glGetProgramiv(m_id, GL_LINK_STATUS, &linked);
    if (!linked)
    {
	containers::Buffer<char, SLIM_DEBUG_MESSAGE_BUFFER_SIZE>	buffer;
	char	error[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

	glGetProgramInfoLog(m_id, SLIM_DEBUG_MESSAGE_BUFFER_SIZE, nullptr, error);
	buffer << "Error linking shader program: " << error;
	throw io::ResourceException(m_name, buffer.getData(), __FILE__, __func__, __LINE__);
    }
}

Program::~Program()
{
    glDeleteProgram(m_id);
}

}
}
