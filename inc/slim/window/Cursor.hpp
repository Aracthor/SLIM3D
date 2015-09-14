namespace slim
{
namespace window
{

const resources::Image*
Cursor::getImage() const
{
    return m_image;
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

}
}
