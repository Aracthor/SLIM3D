#include "slim/debug/Exception.hh"

namespace slim
{
namespace context
{

static int	errorHandler(Display* display, XErrorEvent* event)
{
    char	buffer[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

    XGetErrorText(display, event->error_code, buffer, SLIM_DEBUG_MESSAGE_BUFFER_SIZE);
    SLIM_DEBUG_THROW_EXCEPTION(buffer);
}

ContextImplementation::ContextImplementation()
{
    m_display = XOpenDisplay(nullptr);
    if (m_display == nullptr)
    {
	SLIM_DEBUG_THROW_EXCEPTION("Failed to create display.");
    }
    XSetErrorHandler(&errorHandler);
}

ContextImplementation::~ContextImplementation()
{
    XCloseDisplay(m_display);
}

}
}
