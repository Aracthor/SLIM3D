#ifndef SLIM_GRAPHICS_CONTEXT_HPP_
# define SLIM_GRAPHICS_CONTEXT_HPP_

# include "slim/debug/exit.hpp"
# include "slim/window/Window.hpp"

# define SLIM_GRAPHICS_EGL_CHECK(function, message)	if ((function) == EGL_FALSE) SLIM_DEBUG_EXIT(message)

namespace slim
{
namespace graphics
{

class	Context
{
public:
    Context(window::Window* window);
    ~Context();

public:
    inline void	swapBuffers();

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
