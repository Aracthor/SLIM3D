#ifndef SLIM_WINDOW_WINDOW_HH_
# define SLIM_WINDOW_WINDOW_HH_

# include "slim/events/EventsLoop.hh"
# include "slim/events/EventsManager.hh"

namespace slim
{
namespace window
{

class	Window
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
    Window(unsigned int width, unsigned int height, const char* title, bool fullscreen);
    Window(const Parameters& parameters);
    virtual ~Window();

public:
    inline unsigned int			getWidth() const;
    inline unsigned int			getHeight() const;
    inline const char*			getTitle() const;
    inline events::EventsManager&	getEventsManager();
    inline const events::EventsLoop&	getEventsLoop() const;
    inline events::EventsLoop&		getEventsLoop();

public:
    void		setTitle(const char* title);
    void		resize(unsigned int width, unsigned int height);

public:
    virtual void	display() = 0;

protected:
    virtual void        setTitleImplementation(const char* title) = 0;
    virtual void        resizeImplementation(unsigned int width, unsigned int height) = 0;

protected:
    unsigned int		m_width;
    unsigned int		m_height;
    const char*			m_title;
    bool			m_fullscreen;
    events::EventsManager	m_eventsManager;
    events::EventsLoop		m_eventsLoop;
};

}
}

# include "Window.hpp"

#endif // !SLIM_WINDOW_WINDOW_HH_
