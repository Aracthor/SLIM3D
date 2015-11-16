#include "slim/debug/assert.hpp"

namespace slim
{
namespace window
{

Window*
Window::getCurrent()
{
    SLIM_DEBUG_ASSERT(s_current != nullptr);
    return s_current;
}


unsigned int
Window::getWidth() const
{
    return m_width;
}

unsigned int
Window::getHeight() const
{
    return m_height;
}

const char*
Window::getTitle() const
{
    return m_title;
}

events::Manager&
Window::getEventsManager()
{
    return m_eventsManager;
}

}
}
