#include "slim/context/Context.hh"

namespace slim
{
namespace window
{

WindowImplementation::WindowImplementation(unsigned int width, unsigned int height, const char* title, bool fullscreen) :
    Window(width, height, title, fullscreen)
{
    Display*		        display = context::Context::instance.getImplementation()->getDisplay();

    m_window = XCreateSimpleWindow(display,			// Display singleton
    				   DefaultRootWindow(display),	// Parent window (none in that case)
    				   0, 0,			// Initial position (top-left screen corner)
    				   width, height,		// Size
    				   1, 1,			// Border size
    				   0);				// Background pixel value (0 == black)

    XMapWindow(display, m_window); // Make it visible on screen

    // attributes.event_mask = ExposureMask | PointerMotionMask | KeyPressMask | KeyReleaseMask;
    // m_window = XCreateWindow(display,				// Display
    // 			     DefaultRootWindow(display),	// Parent (none)
    // 			     0, 0,				// Coordinates on the screen (top-left corner)
    // 			     width, height,			// width, height
    // 			     1,					// border width
    // 			     CopyFromParent,			// Depth (default)
    // 			     InputOutput,			// Class
    // 			     CopyFromParent,			// Visual (default)
    // 			     CWEventMask,			// valuemask
    // 			     &attributes);			// attributes

    this->setTitleImplementation(title);
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

}
}
