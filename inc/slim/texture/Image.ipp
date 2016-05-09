namespace slim
{
namespace texture
{

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
