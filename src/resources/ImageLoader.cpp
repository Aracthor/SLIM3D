#include "slim/resources/BMPFormatLoader.hh"
#include "slim/resources/FileException.hh"
#include "slim/resources/ImageLoader.hh"

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

void
ImageLoader::loadImage(const char* fileName, IFormatLoader::ImageData& data)
{
    const char*		extention = this->getExtention(fileName);
    VirtualFile*	file = VirtualFile::fromRealFile(fileName);

    if (!strcmp(extention, "bmp"))
    {
	m_bmpLoader->load(fileName, file, data);
    }
    else
    {
	throw FileException(fileName, "Cannot recognize image format.", __FILE__, __func__, __LINE__);
    }

    delete file;
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
    m_bmpLoader = new BMPFormatLoader();
}

void
ImageLoader::destroy()
{
    delete m_bmpLoader;
}


const char*
ImageLoader::getExtention(const char* fileName) const
{
    const char*	ptr = strrchr(fileName, '.');

    if (ptr == nullptr)
    {
	throw FileException(fileName, "Image file doesn't have any extention.", __FILE__, __func__, __LINE__);
    }

    return (ptr + 1);
}

void
ImageLoader::giveErrorImage(IFormatLoader::ImageData& data) const
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
