#include "slim/debug/assert.hh"

namespace slim
{
namespace window
{

void
Window::resize(unsigned int width, unsigned int height)
{
    glfwSetWindowSize(m_window, width, height);
}

void
Window::setTitle(const char* title)
{
    glfwSetWindowTitle(m_window, title);
}

void
Window::setCursor(Cursor* cursor)
{
    SLIM_DEBUG_ASSERT(cursor->isLoaded());
    glfwSetCursor(m_window, cursor->getGLFWResource());
}

void
Window::resetDefaultCursor()
{
    glfwSetCursor(m_window, nullptr);
}


bool
Window::shouldClose() const
{
    return (glfwWindowShouldClose(m_window) != 0);
}

void
Window::display() const
{
    glfwSwapBuffers(m_window);
}


unsigned int
Window::getWidth() const
{
    return m_parameters.width;
}

unsigned int
Window::getHeight() const
{
    return m_parameters.height;
}

bool
Window::isFullscreen() const
{
    return m_parameters.fullscreen;
}

const char*
Window::getTitle() const
{
    return m_parameters.title;
}

events::EventsManager&
Window::getEventsManager()
{
    return m_eventsManager;
}

const events::EventsLoop&
Window::getEventsLoop() const
{
    return m_eventsLoop;
}

events::EventsLoop&
Window::getEventsLoop()
{
    return m_eventsLoop;
}

}
}
