#ifndef SLIM_WINDOW_CURSOR_HH_
# define SLIM_WINDOW_CURSOR_HH_

# include "slim/engine/glfw.hh"
# include "slim/resources/Image.hh"

namespace slim
{
namespace window
{

class	Cursor
{
public:
    Cursor(const resources::Image* image, unsigned int x = 0, unsigned int y = 0);
    virtual ~Cursor();

public:
    const resources::Image*	getImage() const;

protected:
    GLFWcursor*			m_cursor;
    const resources::Image*	m_image;
};

}
}

# include "Cursor.hpp"

#endif // !SLIM_WINDOW_CURSOR_HH_
