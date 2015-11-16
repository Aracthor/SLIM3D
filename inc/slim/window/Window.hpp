#ifndef SLIM_WINDOW_WINDOW_HPP_
# define SLIM_WINDOW_WINDOW_HPP_

# include "slim/events/Manager.hpp"

# include <EGL/egl.h>

namespace slim
{
namespace window
{

class			Window
{
public:
    struct		Parameters
    {
	unsigned int	width;
	unsigned int	height;
	const char*	title;
	bool		fullscreen;
    };

public:
    static inline Window*	getCurrent();

private:
    static Window*		s_current;


public:
    Window(unsigned int width, unsigned int height, const char* title, bool fullscreen);
    Window(const Parameters& parameters);
    virtual ~Window();

public:
    inline unsigned int			getWidth() const;
    inline unsigned int			getHeight() const;
    inline const char*			getTitle() const;
    inline events::Manager&		getEventsManager();

public:
    void		setTitle(const char* title);
    void		resize(unsigned int width, unsigned int height);

public:
    virtual void			display() = 0;
    virtual void			pollEvents() = 0;
    virtual EGLNativeDisplayType	getEGLDisplay() = 0;
    virtual EGLNativeWindowType		getEGLWindow() = 0;

protected:
    virtual void        setTitleImplementation(const char* title) = 0;
    virtual void        resizeImplementation(unsigned int width, unsigned int height) = 0;

protected:
    unsigned int	m_width;
    unsigned int	m_height;
    const char*		m_title;
    bool		m_fullscreen;
    events::Manager	m_eventsManager;
};

}
}

# include "Window.ipp"

#endif // !SLIM_WINDOW_WINDOW_HPP_
