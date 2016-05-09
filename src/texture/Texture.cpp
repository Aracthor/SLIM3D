#include "slim/debug/LogManager.hpp"
#include "slim/graphics/glDebug.hpp"
#include "slim/texture/Texture.hpp"

namespace slim
{
namespace texture
{

Texture::Texture(memory::Chunk& memory, const char* const name) :
    Image(memory, name)
{
}

Texture::~Texture()
{
}


bool
Texture::loadFromFile(const char* const path)
{
    bool	valid = Image::loadFromFile(path);

    glGenTextures(1, &m_id);
    if (m_id == 0)
    {
	debug::LogManager::instance.graphics.error << "Error trying to create a glTexture for texture " << path << "." << debug::LogStream::endline;
	valid = false;
    }
    else
    {
	this->bind();
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	SLIM_GRAPHICS_GL_CHECK();
	this->unbind();
    }

    return valid;
}

void
Texture::unloadData()
{
    glDeleteTextures(1, &m_id);
    Image::unloadData();
}


}
}
