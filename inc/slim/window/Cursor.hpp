namespace slim
{
namespace window
{

const assets::Image*
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
