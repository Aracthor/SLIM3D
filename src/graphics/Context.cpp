#include "slim/debug/exit.hpp"
#include "slim/debug/LogManager.hpp"
#include "slim/graphics/Context.hpp"

#include <EGL/eglext.h>

namespace slim
{
namespace graphics
{

Context::Context(window::Window* window)
{
    EGLint	configsNumber; // Useless
    EGLint	eglAttribs[] =
	{
	    EGL_RED_SIZE,	5,
	    EGL_GREEN_SIZE,	6,
	    EGL_BLUE_SIZE,	5,
	    EGL_ALPHA_SIZE,     8,
	    EGL_DEPTH_SIZE,	8,
	    EGL_STENCIL_SIZE,	8,
	    EGL_SAMPLE_BUFFERS,	0,
	    EGL_RENDERABLE_TYPE,EGL_OPENGL_ES2_BIT, // TODO check if OpenGL ES 3.0 is supported.
	    EGL_NONE
	};
    EGLint contextAttribs[] =
	{
	    EGL_CONTEXT_CLIENT_VERSION, 2,
	    EGL_NONE
	};

    m_display = eglGetDisplay(window->getEGLDisplay());
    if (m_display == EGL_NO_DISPLAY)
    {
	SLIM_DEBUG_EXIT("Cannot create EGL display.");
    }

    SLIM_GRAPHICS_EGL_CHECK(eglInitialize(m_display, &m_version.major, &m_version.minor),
			    "Cannot initialize EGL.");
    debug::LogManager::instance.graphics.info << "EGL version " << m_version.major << '.' << m_version.minor << " initialized." << debug::LogStream::endline;

    SLIM_GRAPHICS_EGL_CHECK(eglChooseConfig(m_display, eglAttribs, &m_config, 1, &configsNumber),
			    "Cannot set EGL configs.");

    m_surface = eglCreateWindowSurface(m_display, m_config, window->getEGLWindow(), nullptr);
    if (m_surface == EGL_NO_SURFACE)
    {
	SLIM_DEBUG_EXIT("Cannot create EGL surface.");
    }

    m_context = eglCreateContext(m_display, m_config, EGL_NO_CONTEXT, contextAttribs);
    if (m_context == EGL_NO_CONTEXT)
    {
	SLIM_DEBUG_EXIT("Cannot create EGL context.");
    }

    SLIM_GRAPHICS_EGL_CHECK(eglMakeCurrent(m_display, m_surface, m_surface, m_context),
			    "Cannot make created EGL context the current one.");

    debug::LogManager::instance.graphics.info << "Context successfully created." << debug::LogStream::endline;
}

Context::~Context()
{
    SLIM_GRAPHICS_EGL_CHECK(eglMakeCurrent(m_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT),
			    "Cannot disable current EGL context.");
    SLIM_GRAPHICS_EGL_CHECK(eglDestroyContext(m_display, m_context), "Cannot destroy EGL context.");
    SLIM_GRAPHICS_EGL_CHECK(eglDestroySurface(m_display, m_surface), "Cannot destroy EGL surface.");
    SLIM_GRAPHICS_EGL_CHECK(eglTerminate(m_display), "Cannot terminate EGL.");
}

}
}
