#include "slim/window/GLFWException.hh"
#include "slim/window/MonitorsManager.hh"
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
    Window*	window = MonitorsManager::instance.getWindow(glfwWindow);

    window->getEventsManager().onKeyAction
	(static_cast<events::keyboard::EKeyCode>(keycode),
	 scancode,
	 static_cast<events::keyboard::EAction>(action),
	 bitfield);
}

static void
onMouseButton(GLFWwindow* glfwWindow, int button, int action, int bitfield)
{
    Window*	window = MonitorsManager::instance.getWindow(glfwWindow);

    window->getEventsManager().onMouseButtonAction
	(static_cast<events::mouse::EButton>(button),
	 static_cast<events::mouse::EAction>(action),
	 bitfield);
}

static void
onMouseMovement(GLFWwindow* glfwWindow, double x, double y)
{
    Window*	window = MonitorsManager::instance.getWindow(glfwWindow);

    window->getEventsManager().onMouseMovement(x, y);
}

void
Window::initEventsManager()
{
    MonitorsManager::instance.addWindow(m_window, this);
    glfwSetKeyCallback(m_window, &onKey);
    glfwSetMouseButtonCallback(m_window, &onMouseButton);
    glfwSetCursorPosCallback(m_window, &onMouseMovement);
}

}
}
