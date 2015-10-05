#ifndef SLIM_GRAPHICS_GLEXCEPTION_HH_
# define SLIM_GRAPHICS_GLEXCEPTION_HH_

# include "slim/debug/Exception.hh"

# include "slim/graphics/gl.h"

# ifdef _DEBUG
#  define SLIM_GRAPHICS_GL_CHECK(function)	if ((function) == 0) throw slim::graphics::GLException(glGetError(), __FILE__, __func__, __LINE__)
# else
#  define SLIM_GRAPHICS_GL_CHECK(function)	function
# endif

namespace slim
{
namespace graphics
{

class	GLException : public debug::Exception
{
public:
    GLException(GLenum errorCode, const char* file, const char* function, int line);
    virtual ~GLException() throw();
};

}
}

# include "GLException.hpp"

#endif // !SLIM_GRAPHICS_GLEXCEPTION_HH_
