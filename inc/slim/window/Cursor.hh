#ifndef SLIM_WINDOW_CURSOR_HH_
# define SLIM_WINDOW_CURSOR_HH_

# include "slim/assets/Image.hh"
# include "slim/assets/Listener.hh"
# include "slim/engine/glfw.h"
# include "slim/maths/Vector2.hh"

namespace slim
{
namespace window
{

class	Cursor : public assets::Listener
{
public:
    Cursor(const assets::Image* image, unsigned int xhot = 0, unsigned int yhot = 0);
    virtual ~Cursor();

public:
    inline const assets::Image*		getImage() const;
    inline const maths::Vector2ui&	getHot() const;
    inline const GLFWcursor*		getGLFWResource() const;
    inline GLFWcursor*			getGLFWResource();

public:
    void				onAssetsReady() override;

protected:
    GLFWcursor*			m_cursor;
    maths::Vector2ui		m_hot;
    const assets::Image*	m_image;
};

}
}

# include "Cursor.hpp"

#endif // !SLIM_WINDOW_CURSOR_HH_
