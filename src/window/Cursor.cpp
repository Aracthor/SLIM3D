#include "slim/window/Cursor.hh"
#include "slim/window/GLFWException.hh"

namespace slim
{
namespace window
{

Cursor::Cursor(const resources::Image* image, unsigned int xhot, unsigned int yhot) :
    m_image(image)
{
    GLFWimage	glfwImage;

    glfwImage.width = image->getWidth();
    glfwImage.height = image->getHeight();
    glfwImage.pixels = const_cast<unsigned char*>(image->getPixels()); // Need const_cast because GLFW pixels field is not const, but it should be.

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

}
}
