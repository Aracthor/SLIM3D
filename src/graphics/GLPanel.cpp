#include "slim/graphics/GLPanel.hpp"

#include "slim/graphics/gl.h"

namespace slim
{
namespace graphics
{

GLPanel::GLPanel() :
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
GLPanel::clearBuffers()
{
    GLbitfield	mask = GL_COLOR_BUFFER_BIT;

    if (m_depth)
    {
	mask |= GL_DEPTH_BUFFER_BIT;
    }
}

}
}
