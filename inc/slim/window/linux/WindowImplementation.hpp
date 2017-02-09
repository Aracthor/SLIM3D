#include "slim/events/linux/KeyCodeConverter.hpp"
#include "slim/events/linux/MouseButtonConverter.hpp"

#include <X11/Xlib.h>

namespace slim
{
namespace window
{

class		WindowImplementation : public Window
{
public:
    WindowImplementation(unsigned int width, unsigned int height, const char* title, bool fullscreen);
    WindowImplementation(const Parameters& parameters);
    virtual ~WindowImplementation();

public:
    inline void			display() override;
    void			pollEvents() override;
    inline EGLNativeDisplayType	getEGLDisplay() override;
    inline EGLNativeWindowType  getEGLWindow() override;
    inline void			setCursorImplementation(unsigned int x, unsigned int y) override;

protected:
    inline void	setTitleImplementation(const char* title) override;
    inline void	resizeImplementation(unsigned int width, unsigned int height) override;

private:
    void	createDisplay();
    void	createWindow(int width, int height);
    void	allowCloseEvents();

public:
    ::Display*				m_display;
    ::Window				m_window;
    events::KeyCodeConverter		m_keyCodeConverter;
    events::MouseButtonConverter	m_mouseButtonConverter;
};

}
}

#include "WindowImplementation.ipp"
