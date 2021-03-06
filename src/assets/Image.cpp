#include <stdexcept>

#include "slim/data.hpp"
#include "slim/debug/LogManager.hpp"
#include "slim/assets/Image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace slim
{
namespace assets
{

const char* const
Image::typeName = "texture";


Image*
Image::getErrorImage()
{
    Image*	image = new Image("SLIM error image");

    image->setErrorImage();

    return image;
}


Image::Image(const char* name) :
    SingleFileAsset(Image::typeName, name, name)
{
}

Image::Image(const Image& reference) :
    SingleFileAsset(reference),
    m_width(reference.getWidth()),
    m_height(reference.getHeight())
{
    unsigned int	bytesNumber = m_width * m_height * 4;

    m_pixels = new byte[bytesNumber];
    memcpy(m_pixels, reference.m_pixels, bytesNumber);
}

Image::~Image()
{
}


bool
Image::loadFromFile(const char* const path)
{
    try
    {
	int		width, height, comp;
	unsigned int	bytesNumber;
	byte*		image = stbi_load(path, &width, &height, &comp, STBI_rgb_alpha);

	if (image == nullptr)
	{
	    throw std::runtime_error("Couldn't load file.");
	}

	m_width = width;
	m_height = height;
	bytesNumber = m_width * m_height * 4;
	m_pixels = new byte[bytesNumber];
	memcpy(m_pixels, image, bytesNumber);

	stbi_image_free(image);
    }

    catch (std::exception &exception)
    {
	debug::LogManager::instance.assets.error << "Error parsing image " << path << ": " << exception.what() << debug::LogStream::endline;
	this->setErrorImage();
	return false;
    }

    return true;
}

void
Image::unloadData()
{
    delete[] m_pixels;
}


void
Image::setErrorImage()
{
    byte*	pixels = new byte[4];

    pixels[0] = 0xFF;
    pixels[1] = 0xFF;
    pixels[2] = 0xFF;
    pixels[3] = 0xFF;
    this->setData(1, 1, pixels);
}

void
Image::setData(unsigned int width, unsigned int height, byte* pixels)
{
    m_width = width;
    m_height = height;
    m_pixels = pixels;
}

}
}
