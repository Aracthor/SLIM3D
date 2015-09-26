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
