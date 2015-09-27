#ifndef SLIM_WINDOW_CURSOR_HH_
# define SLIM_WINDOW_CURSOR_HH_

# include "slim/engine/glfw.h"
# include "slim/resources/Image.hh"

namespace slim
{
namespace window
{

class	Cursor
{
public:
    enum	EType
    {
	arrow = GLFW_ARROW_CURSOR,
	ibeam = GLFW_IBEAM_CURSOR,
	crosshair = GLFW_CROSSHAIR_CURSOR,
	hand = GLFW_HAND_CURSOR,
	horizontalResize = GLFW_HRESIZE_CURSOR,
	verticalResize = GLFW_VRESIZE_CURSOR
    };

public:
    Cursor*	createStandardCursor(EType type);

public:
    Cursor(const resources::Image* image, unsigned int xhot = 0, unsigned int yhot = 0);
    virtual ~Cursor();

public:
    inline const resources::Image*	getImage() const;
    inline const GLFWcursor*		getGLFWResource() const;
    inline GLFWcursor*			getGLFWResource();

protected:
    GLFWcursor*			m_cursor;
    const resources::Image*	m_image;

private:
    Cursor(GLFWcursor* glfwCursor);
};

}
}

# include "Cursor.hpp"

#endif // !SLIM_WINDOW_CURSOR_HH_
