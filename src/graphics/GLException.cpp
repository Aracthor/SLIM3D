#include "slim/core/string.h"
#include "slim/graphics/GLException.hh"

namespace slim
{
namespace graphics
{

GLException::GLException(GLenum errorCode, const char* file, const char* function, int line) :
    debug::Exception("", file, function, line)
{
    switch (errorCode)
    {
    case GL_NO_ERROR:
	strncpy(m_whatMessage, "No error recorded. But something failed.", SLIM_DEBUG_MESSAGE_BUFFER_SIZE);
	break;
    case GL_INVALID_ENUM:
	strncpy(m_whatMessage, "Unacceptable value for an enumerated argument.", SLIM_DEBUG_MESSAGE_BUFFER_SIZE);
	break;
    case GL_INVALID_OPERATION:
	strncpy(m_whatMessage, "This operation is not allowd at the current state.", SLIM_DEBUG_MESSAGE_BUFFER_SIZE);
	break;
    case GL_INVALID_FRAMEBUFFER_OPERATION:
	strncpy(m_whatMessage, "The framebuffer object is not complete.", SLIM_DEBUG_MESSAGE_BUFFER_SIZE);
	break;
    case GL_OUT_OF_MEMORY:
	strncpy(m_whatMessage, "There is not enough memory left.", SLIM_DEBUG_MESSAGE_BUFFER_SIZE);
	break;
#ifdef GL_STACK_UNDERFLOW
    case GL_STACK_UNDERFLOW:
	strncpy(m_whatMessage, "Internal stack underflow.", SLIM_DEBUG_MESSAGE_BUFFER_SIZE);
	break;
#endif // GL_STACK_UNDERFLOW
#ifdef GL_STACK_OVERFLOW
    case GL_STACK_OVERFLOW:
	strncpy(m_whatMessage, "Internal stack overflow.", SLIM_DEBUG_MESSAGE_BUFFER_SIZE);
	break;
#endif // GL_STACK_OVERFLOW
    default:
	strncpy(m_whatMessage, "Error in error code... Someone made a very creepy thing here.", SLIM_DEBUG_MESSAGE_BUFFER_SIZE);
    }
}

GLException::~GLException() throw()
{
}

}
}
