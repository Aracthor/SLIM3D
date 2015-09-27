#include "slim/debug/assert.hh"
#include "slim/debug/LogManager.hh"
#include "slim/window/Cursor.hh"
#include "slim/window/GLFWException.hh"

namespace slim
{
namespace window
{

Cursor::Cursor(const assets::Image* image, unsigned int xhot, unsigned int yhot) :
    m_hot(xhot, yhot),
    m_image(image)
{
    m_image->setNeeded(true);
    m_image->addListener(this);
}

Cursor::~Cursor()
{
    glfwDestroyCursor(m_cursor);
}


void
Cursor::onLoad(const assets::Image* image)
{
    GLFWimage	glfwImage;

    SLIM_DEBUG_ASSERT(image->isLoaded());

    debug::LogManager::instance.graphics.info << "New cursor created with image " << image->getName() << debug::LogStream::endline;
    glfwImage.width = image->getWidth();
    glfwImage.height = image->getHeight();
    glfwImage.pixels = const_cast<assets::byte*>(image->getPixels());

    m_cursor = glfwCreateCursor(&glfwImage, m_hot.x, m_hot.y);
    if (m_cursor == nullptr)
    {
	throw GLFWException("Couldn't create cursor from an image.", __FILE__, __func__, __LINE__);
    }
}

}
}
