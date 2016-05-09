#include "slim/debug/exit.hpp"
#include "slim/debug/LogManager.hpp"
#include "slim/events/keyboard.hpp"
#include "slim/events/mouse.hpp"

namespace slim
{
namespace window
{

WindowImplementation::WindowImplementation(unsigned int width, unsigned int height, const char* title, bool fullscreen) :
    Window(width, height, title, fullscreen),
    m_keyCodeConverter(m_display)
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
WindowImplementation::pollEvents()
{
    XEvent	event;

    while (XCheckWindowEvent(m_display, m_window, 0xFFFFFFFF, &event) ||
	   XCheckTypedWindowEvent(m_display, m_window, ClientMessage, &event))
    {
	switch (event.type)
	{
	case ClientMessage:
	    m_eventsManager.onClose();
	    break;
	case KeyPress:
	    m_eventsManager.onKeyPressed(m_keyCodeConverter.convert(event.xkey.keycode));
	    break;
	case KeyRelease:
	    m_eventsManager.onKeyReleased(m_keyCodeConverter.convert(event.xkey.keycode));
	    break;
	case ButtonPress:
	    m_eventsManager.onMouseButtonPressed(m_mouseButtonConverter.convert(event.xbutton.button));
	    break;
	case ButtonRelease:
	    m_eventsManager.onMouseButtonReleased(m_mouseButtonConverter.convert(event.xbutton.button));
	    break;
	case MotionNotify:
	    m_eventsManager.onMouseMovement(event.xmotion.x, event.xmotion.y);
	    break;
	}
    }
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
    int				screen;

    screen = DefaultScreen(m_display);
    m_window = XCreateSimpleWindow(m_display,				// Dislpay
				   RootWindow(m_display, screen),	// Parent (none)
				   0, 0,				// x, y
				   width, height,			// width, height
				   1,					// depthx
				   BlackPixel(m_display, screen),	// Border color
				   BlackPixel(m_display, screen));	// Background color
    if (m_window == BadWindow)
    {
	SLIM_DEBUG_EXIT("Cannot create window..");
    }

    if (XSelectInput(m_display, m_window,
		     ExposureMask |
		     KeyPressMask |
		     KeyReleaseMask |
		     ButtonPressMask |
		     ButtonReleaseMask |
		     PointerMotionMask) == BadWindow)
    {
	SLIM_DEBUG_EXIT("Failed to select input mask for window.");
    }

    XMapWindow(m_display, m_window); // Make it visible on screen
    this->allowCloseEvents();
}

void
WindowImplementation::allowCloseEvents()
{
    Atom	deleteProtocol = XInternAtom(m_display, "WM_DELETE_WINDOW", False);

    XSetWMProtocols(m_display, m_window, &deleteProtocol, 1);
}

}
}
