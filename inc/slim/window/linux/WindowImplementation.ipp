namespace slim
{
namespace window
{

void
WindowImplementation::display()
{
    // TODO
    XFlush(m_display);
}

EGLNativeDisplayType
WindowImplementation::getEGLDisplay()
{
    return (EGLNativeDisplayType)m_display;
}

EGLNativeWindowType
WindowImplementation::getEGLWindow()
{
    return (EGLNativeWindowType)m_window;
}

void
WindowImplementation::setCursorImplementation(unsigned int x, unsigned int y)
{
    XWarpPointer(m_display, None, m_window, 0, 0, 0, 0, x, y);
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

}
}
