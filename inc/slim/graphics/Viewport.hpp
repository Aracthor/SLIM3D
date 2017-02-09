#ifndef SLIM_GRAPHICS_VIEWPORT_HPP_
# define SLIM_GRAPHICS_VIEWPORT_HPP_

# include "slim/maths/Vector2.hpp"

namespace slim
{
namespace graphics
{

class	Viewport
{
public:
    Viewport();
    Viewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
    Viewport(const maths::Vector2ui& position, unsigned int width, unsigned int height);
    Viewport(const Viewport& reference);
    ~Viewport();

public:
    void			setAsRenderer() const;

public:
    inline const maths::Vector2ui	getPosition() const;
    inline unsigned int			getWidth() const;
    inline unsigned int			getHeight() const;

private:
    maths::Vector2ui	m_position;
    unsigned int	m_width;
    unsigned int	m_height;
};

}
}

# include "Viewport.ipp"

#endif // !SLIM_GRAPHICS_VIEWPORT_HPP_
