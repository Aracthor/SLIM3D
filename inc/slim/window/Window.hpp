//
// Window.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:02:37 2015 Aracthor
// Last Update Sun Sep 13 09:56:46 2015 Aracthor
//

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


bool
Window::shouldClose() const
{
    return glfwWindowShouldClose(m_window);
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
