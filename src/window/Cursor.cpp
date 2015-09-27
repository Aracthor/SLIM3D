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
    this->listen(m_image);
}

Cursor::~Cursor()
{
    glfwDestroyCursor(m_cursor);
}


void
Cursor::onAssetsReady()
{
    GLFWimage	glfwImage;

    SLIM_DEBUG_ASSERT(m_image->isLoaded());

    debug::LogManager::instance.graphics.info << "New cursor created with image " << m_image->getName() << debug::LogStream::endline;
    glfwImage.width = m_image->getWidth();
    glfwImage.height = m_image->getHeight();
    glfwImage.pixels = const_cast<assets::byte*>(m_image->getPixels());

    m_cursor = glfwCreateCursor(&glfwImage, m_hot.x, m_hot.y);
    if (m_cursor == nullptr)
    {
	throw GLFWException("Couldn't create cursor from an image.", __FILE__, __func__, __LINE__);
    }
}

}
}
