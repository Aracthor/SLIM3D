#include <stdexcept>

#include "slim/debug/Exception.hh"
#include "slim/debug/LogManager.hh"
#include "slim/resources/ImageLoader.hh"
#include "slim/resources/ResourceException.hh"

#include <cstring>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

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
    debug::LogManager::instance.resources.info << "Loading image file " << fileName << "..." << debug::LogStream::endline;

    try
    {
	int		width, height, comp;
	byte*		image = stbi_load(fileName, &width, &height, &comp, STBI_rgb_alpha);

	if (image == nullptr)
	{
	    throw std::runtime_error("Couldn't load file.");
	}

	data.width = width;
	data.height = height;
	data.pixels = new byte[data.width * data.height * 4];
	memcpy(data.pixels, image, data.width * data.height * 4);

	stbi_image_free(image);
    }

    catch (std::exception &exception)
    {
	debug::LogManager::instance.resources.error << "Error parsing image " << fileName << ": " << exception.what() << debug::LogStream::endline;
	return false;
    }

    debug::LogManager::instance.resources.info << "Image file " << fileName << " successfully loaded." << debug::LogStream::endline;

    return true;
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
