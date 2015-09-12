//
// Window.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:02:37 2015 Aracthor
// Last Update Sun Sep 13 01:05:02 2015 Aracthor
//

#include "slim/events/Coordinator.hh"
#include "slim/window/GLFWException.hh"
#include "slim/window/Window.hh"

namespace slim
{
namespace window
{

Window::Window(Parameters parameters) :
    m_parameters(parameters),
    m_eventsManager(),
    m_eventsLoop(m_eventsManager)
{
    m_window = glfwCreateWindow(parameters.width, parameters.height, parameters.title, nullptr, nullptr);
    if (m_window == nullptr)
    {
	throw GLFWException("Couldn't create window.", __FILE__, __func__, __LINE__);
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);

    this->initEventsManager();
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
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

static void
onMouseButton(GLFWwindow* glfwWindow, int button, int action, int bitfield)
{
    Window*	window = events::Coordinator::instance.getWindow(glfwWindow);

    window->getEventsManager().onMouseButtonAction
	(static_cast<events::mouse::EButton>(button),
	 static_cast<events::mouse::EAction>(action),
	 bitfield);
}

static void
onMouseMovement(GLFWwindow* glfwWindow, double x, double y)
{
    Window*	window = events::Coordinator::instance.getWindow(glfwWindow);

    window->getEventsManager().onMouseMovement(x, y);
}

void
Window::initEventsManager()
{
    events::Coordinator::instance.addWindow(this, m_window);
    glfwSetKeyCallback(m_window, &onKey);
    glfwSetMouseButtonCallback(m_window, &onMouseButton);
    glfwSetCursorPosCallback(m_window, &onMouseMovement);
}

}
}
