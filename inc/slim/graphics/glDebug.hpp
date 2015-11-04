#ifndef SLIM_GRAPHICS_GL_DEBUG_HPP_
# define SLIM_GRAPHICS_GL_DEBUG_HPP_

# include "slim/debug/exit.hpp"
# include "slim/graphics/gl.h"

# if _DEBUG
#  define SLIM_GRAPHICS_GL_CHECK(function)	if ((function) == 0) SLIM_DEBUG_EXIT(slim::graphics::getErrorMessage(glGetError()))
# else
#  define SLIM_GRAPHICS_GL_CHECK(function)	function
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
