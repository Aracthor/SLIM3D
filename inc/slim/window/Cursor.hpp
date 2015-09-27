namespace slim
{
namespace window
{

const assets::Image*
Cursor::getImage() const
{
    return m_image;
}

const maths::Vector2ui&
Cursor::getHot() const
{
    return m_hot;
}

const GLFWcursor*
Cursor::getGLFWResource() const
{
    return m_cursor;
}

GLFWcursor*
Cursor::getGLFWResource()
{
    return m_cursor;
}


bool
Cursor::isLoaded() const
{
    return m_image->isLoaded();
}

}
}
