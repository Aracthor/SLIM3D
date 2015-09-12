//
// Window.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:02:37 2015 Aracthor
// Last Update Sat Sep 12 18:35:34 2015 Aracthor
//

#ifndef SLIM_WINDOW_WINDOW_HH_
# define SLIM_WINDOW_WINDOW_HH_

# include <GLFW/glfw3.h>

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
    virtual ~Window();

public:
    bool	shouldClose() const;

public:
    inline void	display() const;

public:
    inline unsigned int	getWidth() const;
    inline unsigned int	getHeight() const;
    inline bool		isFullscreen() const;
    inline const char*	getTitle() const;

private:
    Parameters		m_parameters;
    GLFWwindow*		m_window;
};

}
}

# include "Window.hpp"

#endif // !SLIM_WINDOW_WINDOW_HH_
