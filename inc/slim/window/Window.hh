//
// Window.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:02:37 2015 Aracthor
// Last Update Sat Sep 12 23:20:13 2015 Aracthor
//

#ifndef SLIM_WINDOW_WINDOW_HH_
# define SLIM_WINDOW_WINDOW_HH_

# include <GLFW/glfw3.h>

# include "slim/events/EventsLoop.hh"
# include "slim/events/EventsManager.hh"

# define SLIM_WINDOW_DEFAULT_WIDTH	1600
# define SLIM_WINDOW_DEFAULT_HEIGHT	900
# define SLIM_WINDOW_DEFAULT_FULLSCREEN	true
# define SLIM_WINDOW_DEFAULT_TITLE	"You forgot to give me a name !"

namespace slim
{
namespace window
{

class	Window
{
public:
    struct		Parameters
    {
	unsigned int	width = SLIM_WINDOW_DEFAULT_WIDTH;
	unsigned int	height = SLIM_WINDOW_DEFAULT_HEIGHT;
	bool		fullscreen = SLIM_WINDOW_DEFAULT_FULLSCREEN;
	const char*	title = SLIM_WINDOW_DEFAULT_TITLE;
    };

public:
    Window(Parameters parameters);
    ~Window();

public:
    void	activeFullscreen();

public:
    inline bool	shouldClose() const;
    inline void	display() const;

public:
    inline unsigned int			getWidth() const;
    inline unsigned int			getHeight() const;
    inline bool				isFullscreen() const;
    inline const char*			getTitle() const;
    inline events::EventsManager&	getEventsManager();
    inline const events::EventsLoop&	getEventsLoop() const;
    inline events::EventsLoop&		getEventsLoop();

private:
    void			initEventsManager();

private:
    GLFWwindow*			m_window;
    Parameters			m_parameters;
    events::EventsManager	m_eventsManager;
    events::EventsLoop		m_eventsLoop;
};

}
}

# include "Window.hpp"

#endif // !SLIM_WINDOW_WINDOW_HH_
