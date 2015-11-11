namespace slim
{
namespace graphics
{

const maths::Vector2ui
Viewport::getPosition() const
{
    return m_position;
}

unsigned int
Viewport::getWidth() const
{
    return m_width;
}

unsigned int
Viewport::getHeight() const
{
    return m_height;
}

}
}
