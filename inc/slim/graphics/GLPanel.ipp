namespace slim
{
namespace graphics
{

bool
GLPanel::isDepthEnabled() const
{
    return m_depth;
}

const Viewport&
GLPanel::getViewport() const
{
    return m_viewport;
}

const mesh::Color&
GLPanel::getClearColor() const
{
    return m_clearColor;
}

}
}
