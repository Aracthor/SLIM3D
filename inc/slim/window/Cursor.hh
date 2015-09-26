#ifndef SLIM_WINDOW_CURSOR_HH_
# define SLIM_WINDOW_CURSOR_HH_

# include "slim/assets/Image.hh"
# include "slim/engine/glfw.h"

namespace slim
{
namespace window
{

class	Cursor
{
public:
    Cursor(const assets::Image* image, unsigned int xhot = 0, unsigned int yhot = 0);
    virtual ~Cursor();

public:
    inline const assets::Image*		getImage() const;
    inline const GLFWcursor*		getGLFWResource() const;
    inline GLFWcursor*			getGLFWResource();

protected:
    GLFWcursor*			m_cursor;
    const assets::Image*	m_image;
};

}
}

# include "Cursor.hpp"

#endif // !SLIM_WINDOW_CURSOR_HH_
