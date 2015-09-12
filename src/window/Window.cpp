//
// Window.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:02:37 2015 Aracthor
// Last Update Sat Sep 12 23:24:36 2015 Aracthor
//

#include "slim/events/Coordinator.hh"
#include "slim/window/GLFWException.hh"
#include "slim/window/Window.hh"

#include <iostream> // DEBUG

namespace slim
{
namespace window
{

Window::Window(Parameters parameters) :
    m_parameters(parameters),
    m_eventsManager(),
    m_eventsLoop(m_eventsManager)
{
    GLFWmonitor*	monitor = nullptr;

    if (parameters.fullscreen)
    {
	monitor = glfwGetPrimaryMonitor();
	if (monitor == nullptr)
	{
	    throw GLFWException("Cannot get primary monitor.", __FILE__, __func__, __LINE__);
	}
    }

    m_window = glfwCreateWindow(parameters.width, parameters.height, parameters.title, monitor, nullptr);
    if (m_window == nullptr)
    {
	throw GLFWException("Couldn't create window.", __FILE__, __func__, __LINE__);
    }

    if (parameters.fullscreen)
    {
	this->activeFullscreen();
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);

    this->initEventsManager();
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
}


void
Window::activeFullscreen()
{
    // TODO
}


static void
onKey(GLFWwindow* glfwWindow, int keycode, int scancode, int action, int bitfield)
{
    Window*	window = events::Coordinator::instance.getWindow(glfwWindow);

    window->getEventsManager().onKeyAction
	(static_cast<events::keyboard::EKeyCode>(keycode),
	 scancode,
	 static_cast<events::keyboard::EAction>(action),
	 bitfield);
}

void
Window::initEventsManager()
{
    events::Coordinator::instance.addWindow(this, m_window);
    glfwSetKeyCallback(m_window, &onKey);
}

}
}
