#ifndef SLIM_GRAPHICS_G_L_PANEL_HPP_
# define SLIM_GRAPHICS_G_L_PANEL_HPP_

# include "slim/graphics/Viewport.hpp"
# include "slim/mesh/data.hpp"

# define SLIM_GRAPHICS_DEFAULT_CLEAR_COLOR	SLIM_MESH_BLACK_COLOR
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
    inline const mesh::Color&	getClearColor() const;

public:
    void			setViewport(const Viewport& viewport);
    void			setViewport(unsigned int x, unsigned int y,
					    unsigned int width, unsigned int height);
    void			setClearColor(const mesh::Color& color);

public:
    void			clearBuffers() const;

private:
    Viewport	m_viewport;
    mesh::Color	m_clearColor;
    bool	m_depth;
};

}
}

# include "GLPanel.ipp"

#endif // !SLIM_GRAPHICS_G_L_PANEL_HPP_
