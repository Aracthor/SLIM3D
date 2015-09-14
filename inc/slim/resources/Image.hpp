namespace slim
{
namespace resources
{

const char*
Image::getName() const
{
    return m_name;
}

unsigned int
Image::getWidth() const
{
    return m_width;
}

unsigned int
Image::getHeight() const
{
    return m_height;
}

const byte*
Image::getPixels() const
{
    return m_pixels;
}

}
}
