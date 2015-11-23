#ifndef SLIM_GRAPHICS_GL_DEBUG_HPP_
# define SLIM_GRAPHICS_GL_DEBUG_HPP_

# include "slim/debug/exit.hpp"
# include "slim/graphics/gl.h"

# define SLIM_GRAPHICS_DEBUG_EXIT()		SLIM_DEBUG_EXIT(slim::graphics::getErrorMessage(glGetError()))
# if _DEBUG
#  define SLIM_GRAPHICS_GL_CHECK()		if (glGetError() != GL_NO_ERROR) SLIM_GRAPHICS_DEBUG_EXIT()
#  define SLIM_GRAPHICS_GL_ASSERT(function)	if ((function) == 0) SLIM_GRAPHICS_DEBUG_EXIT()
# else
#  define SLIM_GRAPHICS_GL_CHECK()
#  define SLIM_GRAPHICS_GL_ASSERT(function)	function
# endif

# define SLIM_GRAPHICS_GL_ERRORS_NUMBER	10

namespace slim
{
namespace graphics
{

const char*
getErrorMessage(GLenum code);

}
}

#endif // !SLIM_GRAPHICS_GL_DEBUG_HPP_
