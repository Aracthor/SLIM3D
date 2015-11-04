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
    void			display() override;
    void			pollEvents() override;
    EGLNativeDisplayType	getEGLDisplay() override;
    EGLNativeWindowType		getEGLWindow() override;

protected:
    void	setTitleImplementation(const char* title) override;
    void	resizeImplementation(unsigned int width, unsigned int height) override;

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
