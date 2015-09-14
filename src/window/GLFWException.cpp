#include "slim/window/GLFWException.hh"

namespace slim
{
namespace window
{

GLFWException::GLFWException(const char* message, const char* file, const char* function, int line) :
    debug::Exception(message, file, function, line)
{
}

GLFWException::~GLFWException() throw()
{
}

}
}
