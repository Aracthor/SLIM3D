#include "slim/graphics/GLPanel.hpp"

#include "slim/graphics/gl.h"

namespace slim
{
namespace graphics
{

GLPanel::GLPanel() :
    m_clearColor(SLIM_GRAPHICS_DEFAULT_CLEAR_COLOR),
    m_depth(SLIM_GRAPHICS_DEFAULT_DEPTH_ENABLED)
{
}

GLPanel::~GLPanel()
{
}


void
GLPanel::setViewport(const Viewport& viewport)
{
    m_viewport = viewport;
    m_viewport.setAsRenderer();
}

void
GLPanel::setViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
    Viewport	viewport(x, y, width, height);

    this->setViewport(viewport);
}

void
GLPanel::setClearColor(const mesh::Color& color)
{
    m_clearColor = color;
    glClearColor(color.x, color.y, color.z, color.w);
}


void
GLPanel::clearBuffers() const
{
    GLbitfield	mask = GL_COLOR_BUFFER_BIT;

    if (m_depth)
    {
	mask |= GL_DEPTH_BUFFER_BIT;
    }
    glClear(mask);
}

}
}
