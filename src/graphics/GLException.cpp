#include "slim/graphics/GLException.hh"

namespace slim
{
namespace graphics
{

const char*
GLException::s_errorMessages[SLIM_GRAPHICS_GL_ERRORS_NUMBER] =
{
    "No error..."
};


GLException::GLException(GLenum errorCode, const char* file, const char* function, int line) :
    debug::Exception("", file, function, line)
{
    (void)errorCode;
    // TODO
}

GLException::~GLException() throw()
{
}

}
}
