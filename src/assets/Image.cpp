#include "slim/debug/LogManager.hh"
#include "slim/assets/Image.hh"

#include <cstring>

namespace slim
{
namespace assets
{

ImageLoader
Image::s_imageLoader;


Image*
Image::getErrorImage()
{
    byte*	pixels = new byte[4];

    pixels[0] = 0xFF;
    pixels[1] = 0xFF;
    pixels[2] = 0xFF;
    pixels[3] = 0xFF;
    return new Image("SLIM error image", 1, 1, pixels);
}


Image*
Image::createFromFile(const char* fileName)
{
    ImageLoader::ImageData	data;
    Image*			image;

    if (s_imageLoader.loadImage(fileName, data) == true)
    {
	image = new Image(fileName, data.width, data.height, data.pixels);
    }
    else
    {
	debug::LogManager::instance.assets.warning << "Couldn't load image " << fileName << debug::LogStream::endline;
	image = Image::getErrorImage();
    }

    return image;
}

Image::Image(const char* name, unsigned int width, unsigned int height, byte* pixels) :
    Asset(SLIM_ASSETS_IMAGE_ASSET_TYPE, name),
    m_width(width),
    m_height(height),
    m_pixels(pixels)
{
}


Image::Image(const Image& reference) :
    Asset(reference),
    m_width(reference.getWidth()),
    m_height(reference.getHeight())
{
    unsigned int	pixelsNumber = m_width * m_height;

    m_pixels = new byte[pixelsNumber];
    memcpy(m_pixels, reference.m_pixels, pixelsNumber);
}

Image::~Image()
{
    delete[] m_pixels;
}

}
}
