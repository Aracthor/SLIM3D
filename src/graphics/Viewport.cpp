#include "slim/graphics/Viewport.hpp"

#include "slim/graphics/gl.h"

namespace slim
{
namespace graphics
{

Viewport::Viewport() :
    m_position(0, 0),
    m_width(0),
    m_height(0)
{
}

Viewport::Viewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) :
    m_position(x, y),
    m_width(width),
    m_height(height)
{
}

Viewport::Viewport(const maths::Vector2ui& position, unsigned int width, unsigned int height) :
    m_position(position),
    m_width(width),
    m_height(height)
{
}

Viewport::Viewport(const Viewport& reference) :
    m_position(reference.getPosition()),
    m_width(reference.getWidth()),
    m_height(reference.getHeight())
{
}

Viewport::~Viewport()
{
}


void
Viewport::setAsRenderer() const
{
    glViewport(m_position.x, m_position.y, m_width, m_height);
}

}
}
