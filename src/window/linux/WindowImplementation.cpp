#include "slim/context/Context.hpp"
#include "slim/debug/LogManager.hpp"

namespace slim
{
namespace window
{

WindowImplementation::WindowImplementation(unsigned int width, unsigned int height, const char* title, bool fullscreen) :
    Window(width, height, title, fullscreen)
{
    Display*			display = context::Context::instance.getImplementation()->getDisplay();
    XSetWindowAttributes	attributes;

    // m_window = XCreateSimpleWindow(display,			// Display singleton
    // 				   DefaultRootWindow(display),	// Parent window (none in that case)
    // 				   0, 0,			// Initial position (top-left screen corner)
    // 				   width, height,		// Size
    // 				   1, 1,			// Border size
    // 				   0);				// Background pixel value (0 == black)



    attributes.event_mask = 0xFFFFFF;
    m_window = XCreateWindow(display,				// Display
			     DefaultRootWindow(display),	// Parent (none)
			     0, 0,				// x, y
			     width, height,			// width, height
			     1,					// border width
			     CopyFromParent,			// depthx
			     InputOutput,			// class
			     CopyFromParent,			// visual
			     CWEventMask,			// valuemask
			     &attributes);			// attributes

    this->allowCloseEvents();
    XMapWindow(display, m_window); // Make it visible on screen
    this->setTitleImplementation(title);

    // XEvent	ev;
    // XWindowEvent(display, m_window, ExposureMask, &ev);
    // XPutBackEvent(display, &ev);

}

WindowImplementation::WindowImplementation(const Parameters& parameters) :
    WindowImplementation(parameters.width, parameters.height, parameters.title, parameters.fullscreen)
{
}

WindowImplementation::~WindowImplementation()
{
    XDestroyWindow(context::Context::instance.getImplementation()->getDisplay(), m_window);
}


void
WindowImplementation::display()
{
    Display*	display = context::Context::instance.getImplementation()->getDisplay();

    // TODO
    XFlush(display);
}


void
WindowImplementation::resizeImplementation(unsigned int width, unsigned int height)
{
    XResizeWindow(context::Context::instance.getImplementation()->getDisplay(), m_window, width, height);
}

void
WindowImplementation::setTitleImplementation(const char* title)
{
    XStoreName(context::Context::instance.getImplementation()->getDisplay(), m_window, title);
}


void
WindowImplementation::allowCloseEvents()
{
    Display*	display = context::Context::instance.getImplementation()->getDisplay();
    Atom	deleteProtocol = XInternAtom(display, "WM_DELETE_WINDOW", True);
    XSetWMProtocols(display, m_window, &deleteProtocol, 1);
}

}
}
