#include "slim/resources/Image.hh"

#include <cstring>

namespace slim
{
namespace resources
{

Image::Image(const char* fileName)
{
    (void)fileName;
}

Image::Image(const Image& reference) :
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
