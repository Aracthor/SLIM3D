#include "slim/resources/ImageLoader.hh"
#include "slim/resources/ResourceException.hh"

#include <cstring>

namespace slim
{
namespace resources
{

ImageLoader::ImageLoader()
{
}

ImageLoader::~ImageLoader()
{
}


void
ImageLoader::preventImageCreation()
{
    if (m_counter == 0)
    {
	this->init();
    }
    m_counter++;
}

bool
ImageLoader::loadImage(const char* fileName, ImageLoader::ImageData& data)
{
    (void)fileName;
    (void)data;

    return false;
}

void
ImageLoader::preventImageDeletion()
{
    m_counter--;
    if (m_counter == 0)
    {
	this->destroy();
    }
}


void
ImageLoader::init()
{
}

void
ImageLoader::destroy()
{
}


const char*
ImageLoader::getExtention(const char* fileName) const
{
    const char*	ptr = strrchr(fileName, '.');

    if (ptr == nullptr)
    {
	throw ResourceException(fileName, "Image file doesn't have any extention.", __FILE__, __func__, __LINE__);
    }

    return (ptr + 1);
}

void
ImageLoader::giveErrorImage(ImageLoader::ImageData& data) const
{
    // A single white pixel.
    data.width = 1;
    data.height = 1;
    data.pixels = new byte[4];
    data.pixels[0] = 0xFF;
    data.pixels[1] = 0xFF;
    data.pixels[2] = 0xFF;
    data.pixels[3] = 0xFF;
}

}
}
