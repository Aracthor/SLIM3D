#include "slim/containers/Buffer.hh"
#include "slim/debug/LogManager.hh"
#include "slim/graphics/GLException.hh"
#include "slim/io/VirtualFile.hh"
#include "slim/shader/Shader.hh"

namespace slim
{
namespace shader
{

const char* const
Shader::typeName = "shader";


Shader::Shader(const char* name, EType type) :
    assets::SingleFileAsset(Shader::typeName, name, name),
    m_type(type)
{
}

Shader::~Shader()
{
}


bool
Shader::loadFromFile(const char* const path)
{
    io::VirtualFile	file = io::VirtualFile::fromRealFile(path);
    char		buffer[SLIM_SHADER_FILE_BUFFER_SIZE];

    file.toBuffer(buffer, SLIM_SHADER_FILE_BUFFER_SIZE);
    return this->readFromData(buffer);
}


void
Shader::unloadData()
{
    glDeleteShader(m_id);
}


bool
Shader::readFromData(const char* const data)
{
    GLint	compiled;

    debug::LogManager::instance.graphics.info << "Compiling shader \"" << this->getName() << "\"..." << debug::LogStream::endline;

    // TODO what are those nullptr ?
    SLIM_GRAPHICS_GL_CHECK(m_id = glCreateShader(m_type));
    glShaderSource(m_id, 1, &data, nullptr);
    glCompileShader(m_id);

    glGetShaderiv(m_id, GL_COMPILE_STATUS, &compiled);
    if (!compiled)
    {
	char	error[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

	glGetShaderInfoLog(m_id, SLIM_DEBUG_MESSAGE_BUFFER_SIZE, nullptr, error);
	debug::LogManager::instance.graphics.error << "Error compiling shader " << this->getName() << ": " << error << debug::LogStream::endline;
    }

    debug::LogManager::instance.graphics.info << "Compiled shader \"" << this->getName() << "\"." << debug::LogStream::endline;

    return compiled;
}

}
}
