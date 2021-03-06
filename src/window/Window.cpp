#include "slim/debug/LogManager.hpp"
#include "slim/window/Window.hpp"

namespace slim
{
namespace window
{

Window*
Window::s_current = nullptr;


Window::Window(unsigned int width, unsigned int height, const char* title, bool fullscreen) :
    m_width(width),
    m_height(height),
    m_title(title),
    m_fullscreen(fullscreen),
    m_eventsManager()
{
    debug::LogManager::instance.graphics.info << "Window created: " << title << debug::LogStream::endline;
    s_current = this;
}

Window::Window(const Parameters& parameters) :
    Window(parameters.width, parameters.height, parameters.title, parameters.fullscreen)
{
}

Window::~Window()
{
    debug::LogManager::instance.graphics.info << "Window " << m_title << " destroyed" << debug::LogStream::endline;
}


void
Window::setTitle(const char* title)
{
    const char*	oldTitle = m_title;
    m_title = title;
    this->setTitleImplementation(title);
    debug::LogManager::instance.graphics.info << "Window " << oldTitle << " renamed to: " << title << debug::LogStream::endline;
}

void
Window::resize(unsigned int width, unsigned int height)
{
    m_width = width;
    m_height = height;
    this->resizeImplementation(width, height);
    debug::LogManager::instance.graphics.info << "Window " << m_title <<  " resized to " << width << 'x' << height << debug::LogStream::endline;
}

void
Window::setCursor(unsigned int x, unsigned int y)
{
    m_eventsManager.setNextMouseMovementForced();
    this->setCursorImplementation(x, y);
}

}
}
