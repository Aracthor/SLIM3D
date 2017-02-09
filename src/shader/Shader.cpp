#include "slim/containers/Buffer.hpp"
#include "slim/debug/LogManager.hpp"
#include "slim/graphics/glDebug.hpp"
#include "slim/io/VirtualFile.hpp"
#include "slim/shader/Shader.hpp"

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

    debug::LogManager::instance.assets.info << "Compiling shader \"" << this->getName() << "\"..." << debug::LogStream::endline;

    SLIM_GRAPHICS_GL_ASSERT(m_id = glCreateShader(m_type));
    glShaderSource(m_id, 1, &data, nullptr);
    glCompileShader(m_id);

    glGetShaderiv(m_id, GL_COMPILE_STATUS, &compiled);
    if (!compiled)
    {
	char	error[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

	glGetShaderInfoLog(m_id, SLIM_DEBUG_MESSAGE_BUFFER_SIZE, nullptr, error);
	if (glGetError() != GL_NO_ERROR)
	{
	    SLIM_DEBUG_EXIT("Error trying to read ", this->getName(), " shader info log: ", graphics::getErrorMessage(glGetError()));
	}
	debug::LogManager::instance.graphics.error << "Error compiling shader " << this->getName() << ": " << error << debug::LogStream::endline;
    }
    else
    {
	debug::LogManager::instance.graphics.info << "Compiled shader \"" << this->getName() << "\"." << debug::LogStream::endline;
    }

    return compiled;
}

}
}
