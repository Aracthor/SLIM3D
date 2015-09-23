#include "slim/containers/Buffer.hh"
#include "slim/graphics/GLException.hh"
#include "slim/resources/ResourceException.hh"
#include "slim/shader/Shader.hh"

namespace slim
{
namespace shader
{

Shader::Shader(EType type, resources::ReadingFile& file) :
    m_name(file.getName()),
    m_type(type)
{
    this->readFromFile(file);
}

Shader::Shader(const char* name, EType type, resources::VirtualFile& file) :
    m_name(name),
    m_type(type)
{
    this->readFromFile(file);
}

Shader::Shader(const char* name, EType type, const char* data) :
    m_name(name),
    m_type(type)
{
    this->readFromData(data);
}

Shader::~Shader()
{
    glDeleteShader(m_id);
}


void
Shader::readFromFile(resources::ReadingFile& file)
{
    this->readFromFile(resources::VirtualFile::fromRealFile(file));
}

void
Shader::readFromFile(const resources::VirtualFile& file)
{
    this->readFromData(reinterpret_cast<const char*>(file.getData()));
}

void
Shader::readFromData(const char* data)
{
    GLint	compiled;

    // TODO what are those nullptr ?
    SLIM_GRAPHICS_GL_CHECK(m_id = glCreateShader(m_type));
    glShaderSource(m_id, 1, &data, nullptr);
    glCompileShader(m_id);

    glGetShaderiv(m_id, GL_COMPILE_STATUS, &compiled);
    if (!compiled)
    {
	containers::Buffer<char, SLIM_DEBUG_MESSAGE_BUFFER_SIZE>	buffer;
	char	error[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

	glGetShaderInfoLog(m_id, SLIM_DEBUG_MESSAGE_BUFFER_SIZE, nullptr, error);
	buffer << "Error compiling shader: " << error;
	throw resources::ResourceException(m_name, buffer.getData(), __FILE__, __func__, __LINE__);
    }
}

}
}
