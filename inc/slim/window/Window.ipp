namespace slim
{
namespace window
{

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
