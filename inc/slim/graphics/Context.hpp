#ifndef SLIM_GRAPHICS_CONTEXT_HPP_
# define SLIM_GRAPHICS_CONTEXT_HPP_

# include "slim/window/Window.hpp"

namespace slim
{
namespace graphics
{

class	Context
{
public:
    Context(window::Window* window);
    ~Context();

private:
    struct	Version
    {
	EGLint	major;
	EGLint	minor;
    };

private:
    EGLDisplay	m_display;
    EGLConfig	m_config;
    EGLSurface	m_surface;
    EGLContext	m_context;
    Version	m_version;
};

}
}

# include "Context.ipp"

#endif // !SLIM_GRAPHICS_CONTEXT_HPP_
