#include "slim/resources/Image.hh"

#include <cstring>

namespace slim
{
namespace resources
{

ImageLoader
Image::s_imageLoader;

const Image
Image::s_errorImage = Image();

const byte
Image::s_errorImagePixels[4] = {0xFF, 0xFF, 0xFF, 0xFF};


const Image&
Image::getErrorImage()
{
    return s_errorImage;
}


// Single white pixel
Image::Image() :
    m_name("SLIM error image"),
    m_width(1),
    m_height(1)
{
    m_pixels = const_cast<byte*>(s_errorImagePixels);
}


Image::Image(const char* fileName)
{
    IFormatLoader::ImageData	data;

    s_imageLoader.preventImageCreation();
    s_imageLoader.loadImage(fileName, data);
    m_width = data.width;
    m_height = data.height;
    m_pixels = data.pixels;
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
