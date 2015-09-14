#include "slim/debug/LogManager.hh"
#include "slim/resources/Image.hh"

#include <cstring>

namespace slim
{
namespace resources
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


Image::Image(const char* name, unsigned int width, unsigned int height, byte* pixels) :
    m_name(name),
    m_width(width),
    m_height(height),
    m_pixels(pixels)
{
}


Image*
Image::createFromFile(const char* fileName)
{
    IFormatLoader::ImageData	data;
    Image*			image;

    s_imageLoader.preventImageCreation();
    if (s_imageLoader.loadImage(fileName, data) == true)
    {
	image = new Image(fileName, data.width, data.height, data.pixels);
    }
    else
    {
	debug::LogManager::instance.resources.warning << "Couldn't load image " << fileName << debug::LogStream::endline;
	image = Image::getErrorImage();
    }

    return image;
}

Image::Image(const Image& reference) :
    m_width(reference.getWidth()),
    m_height(reference.getHeight())
{
    unsigned int	pixelsNumber = m_width * m_height;

    s_imageLoader.preventImageCreation();
    m_pixels = new byte[pixelsNumber];
    memcpy(m_pixels, reference.m_pixels, pixelsNumber);
}

Image::~Image()
{
    delete[] m_pixels;
    s_imageLoader.preventImageDeletion();
}

}
}
