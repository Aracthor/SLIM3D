#include <stdexcept>

#include "slim/assets/Exception.hh"
#include "slim/assets/ImageLoader.hh"
#include "slim/debug/LogManager.hh"

#include <cstring>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace slim
{
namespace assets
{

ImageLoader::ImageLoader()
{
}

ImageLoader::~ImageLoader()
{
}


bool
ImageLoader::loadImage(const char* fileName, ImageLoader::ImageData& data)
{
    debug::LogManager::instance.assets.info << "Loading image file " << fileName << "..." << debug::LogStream::endline;

    try
    {
	int	width, height, comp;
	byte*   image = stbi_load(fileName, &width, &height, &comp, STBI_rgb_alpha);

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
	debug::LogManager::instance.assets.error << "Error parsing image " << fileName << ": " << exception.what() << debug::LogStream::endline;
	return false;
    }

    debug::LogManager::instance.assets.info << "Image file " << fileName << " successfully loaded." << debug::LogStream::endline;

    return true;
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
