#include "slim/window/Cursor.hh"
#include "slim/window/GLFWException.hh"

namespace slim
{
namespace window
{

Cursor*
Cursor::createStandardCursor(EType type)
{
    GLFWcursor*	glfwCursor = glfwCreateStandardCursor(type);
    if (glfwCursor == nullptr)
    {
	throw GLFWException("Couldn't create standard cursor.", __FILE__, __func__, __LINE__);
    }

    return new Cursor(glfwCursor);
}


Cursor::Cursor(const resources::Image* image, unsigned int xhot, unsigned int yhot) :
    m_image(image)
{
    GLFWimage	glfwImage;

    glfwImage.width = image->getWidth();
    glfwImage.height = image->getHeight();
    glfwImage.pixels = const_cast<unsigned char*>(image->getPixels());

    m_cursor = glfwCreateCursor(&glfwImage, xhot, yhot);
    if (m_cursor == nullptr)
    {
	throw GLFWException("Couldn't create cursor from an image.", __FILE__, __func__, __LINE__);
    }
}

Cursor::~Cursor()
{
    glfwDestroyCursor(m_cursor);
}


Cursor::Cursor(GLFWcursor* glfwCursor) :
    m_cursor(glfwCursor),
    m_image(nullptr)
{
}

}
}
