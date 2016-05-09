#include <stdexcept>

#include "slim/data.hpp"
#include "slim/debug/LogManager.hpp"
#include "slim/texture/Image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace slim
{
namespace texture
{

const char* const
Image::typeName = "texture";


Image::Image(memory::Chunk& memory, const char* const name) :
    SingleFileAsset(Image::typeName, name, name),
    m_memory(memory)
{
}

Image::~Image()
{
}


bool
Image::loadFromFile(const char* const path)
{
    int		width, height, comp;
    unsigned int	bytesNumber;
    byte*		image = stbi_load(path, &width, &height, &comp, STBI_rgb_alpha);

    debug::LogManager::instance.assets.info << "Loading image " << path << "..." << debug::LogStream::endline;
    if (image == nullptr)
    {	
	debug::LogManager::instance.assets.error << "Error parsing image " << path << "." << debug::LogStream::endline; 
	this->setErrorImage();
	return false;
    }

    m_width = width;
    m_height = height;
    bytesNumber = m_width * m_height * 4;
    m_pixels = new byte[bytesNumber];
    memcpy(m_pixels, image, bytesNumber);

    stbi_image_free(image);
    debug::LogManager::instance.assets.info << "Loaded image " << path << "." << debug::LogStream::endline;

    return true;
}

void
Image::unloadData()
{
    delete[] m_pixels;
}


void
Image::setErrorImage()
{
    byte*	pixels = new byte[4];

    pixels[0] = 0xFF;
    pixels[1] = 0xFF;
    pixels[2] = 0xFF;
    pixels[3] = 0xFF;
    this->setData(1, 1, pixels);
}

void
Image::setData(unsigned int width, unsigned int height, byte* pixels)
{
    m_width = width;
    m_height = height;
    m_pixels = pixels;
}

}
}
