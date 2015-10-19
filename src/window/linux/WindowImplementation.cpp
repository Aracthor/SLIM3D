#include "slim/debug/exit.hpp"
#include "slim/debug/LogManager.hpp"

namespace slim
{
namespace window
{

WindowImplementation::WindowImplementation(unsigned int width, unsigned int height, const char* title, bool fullscreen) :
    Window(width, height, title, fullscreen)
{
    this->createDisplay();
    this->createWindow(width, height);
    this->setTitleImplementation(title);
}

WindowImplementation::WindowImplementation(const Parameters& parameters) :
    WindowImplementation(parameters.width, parameters.height, parameters.title, parameters.fullscreen)
{
}

WindowImplementation::~WindowImplementation()
{
    XDestroyWindow(m_display, m_window);
    XCloseDisplay(m_display);
}


void
WindowImplementation::display()
{
    // TODO
    XFlush(m_display);
}


void
WindowImplementation::resizeImplementation(unsigned int width, unsigned int height)
{
    XResizeWindow(m_display, m_window, width, height);
}

void
WindowImplementation::setTitleImplementation(const char* title)
{
    XStoreName(m_display, m_window, title);
}

static int
errorHandler(Display* display, XErrorEvent* event)
{
    char	buffer[0x1000];

    XGetErrorText(display, event->error_code, buffer, 0x1000);
    SLIM_DEBUG_EXIT(buffer);
}

void
WindowImplementation::createDisplay()
{
    m_display = XOpenDisplay(nullptr);
    if (m_display == nullptr)
    {
	SLIM_DEBUG_EXIT("Failed to create display.");
    }
    XSetErrorHandler(&errorHandler);
}

void
WindowImplementation::createWindow(int width, int height)
{
    XSetWindowAttributes	attributes;

    attributes.event_mask = 0xFFFFFF;
    m_window = XCreateWindow(m_display,				// Display
			     DefaultRootWindow(m_display),	// Parent (none)
			     0, 0,				// x, y
			     width, height,			// width, height
			     1,					// border width
			     CopyFromParent,			// depthx
			     InputOutput,			// class
			     CopyFromParent,			// visual
			     CWEventMask,			// valuemask
			     &attributes);			// attributes

    this->allowCloseEvents();
    XMapWindow(m_display, m_window); // Make it visible on screen
}

void
WindowImplementation::allowCloseEvents()
{
    Atom	deleteProtocol = XInternAtom(m_display, "WM_DELETE_WINDOW", True);

    XSetWMProtocols(m_display, m_window, &deleteProtocol, 1);
}

}
}
