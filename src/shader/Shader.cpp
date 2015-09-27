#include "slim/containers/Buffer.hh"
#include "slim/graphics/GLException.hh"
#include "slim/io/ResourceException.hh"
#include "slim/shader/Shader.hh"

namespace slim
{
namespace shader
{

Shader::Shader(EType type, io::ReadingFile& file) :
    m_name(file.getName()),
    m_type(type)
{
    this->readFromFile(file);
}

Shader::Shader(const char* name, EType type, io::VirtualFile& file) :
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
Shader::readFromFile(io::ReadingFile& file)
{
    this->readFromFile(io::VirtualFile::fromRealFile(file));
}

void
Shader::readFromFile(const io::VirtualFile& file)
{
    char	buffer[SLIM_SHADER_FILE_BUFFER_SIZE];

    file.toBuffer(buffer, SLIM_SHADER_FILE_BUFFER_SIZE);
    this->readFromData(buffer);
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
	throw io::ResourceException(m_name, buffer.getData(), __FILE__, __func__, __LINE__);
    }
}

}
}
