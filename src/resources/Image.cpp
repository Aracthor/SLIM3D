#include "slim/resources/Image.hh"

#include <cstring>

namespace slim
{
namespace resources
{

ImageLoader
Image::s_imageLoader;


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
