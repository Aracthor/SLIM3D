#include "slim/resources/Image.hh"

#include <cstring>

namespace slim
{
namespace resources
{

ImageLoader
Image::s_imageLoader;


Image::Image()
{
    s_imageLoader.preventImageCreation();
}

Image::Image(const char* fileName) :
    Image()
{
    (void)fileName;
}

Image::Image(const Image& reference) :
    Image()
{
    unsigned int	pixelsNumber = m_width * m_height;

    m_width = reference.getWidth();
    m_height = reference.getHeight();
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
