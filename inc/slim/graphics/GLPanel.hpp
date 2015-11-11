#ifndef SLIM_GRAPHICS_G_L_PANEL_HPP_
# define SLIM_GRAPHICS_G_L_PANEL_HPP_

# include "slim/graphics/Viewport.hpp"

# define SLIM_GRAPHICS_DEFAULT_DEPTH_ENABLED	true

namespace slim
{
namespace graphics
{

class	GLPanel
{
public:
    GLPanel();
    virtual ~GLPanel();

public:
    inline bool			isDepthEnabled() const;
    inline const Viewport&	getViewport() const;

public:
    void			setViewport(const Viewport& viewport);
    void			setViewport(unsigned int x, unsigned int y,
					    unsigned int width, unsigned int height);

public:
    void			clearBuffers();

private:
    Viewport	m_viewport;
    bool	m_depth;
};

}
}

# include "GLPanel.ipp"

#endif // !SLIM_GRAPHICS_G_L_PANEL_HPP_
