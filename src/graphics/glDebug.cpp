#include "slim/containers/ConstMap.hpp"
#include "slim/graphics/glDebug.hpp"

namespace slim
{
namespace graphics
{

const char*
getErrorMessage(GLenum code)
{
    static const GLenum	codes[SLIM_GRAPHICS_GL_ERRORS_NUMBER] = {
	GL_NO_ERROR,
	GL_INVALID_ENUM,
	GL_INVALID_VALUE,
	GL_INVALID_OPERATION,
	GL_OUT_OF_MEMORY,
	GL_INVALID_FRAMEBUFFER_OPERATION
    };
    static const char*	messages[SLIM_GRAPHICS_GL_ERRORS_NUMBER] = {
	"No error detected... Wich is weird...",
	"Invalid enum parameter",
	"Invalid value parameter",
	"Invalid operation",
	"Out of memory",
	"Trying to access to a not complete framebuffer"
    };
    static containers::ConstMap<GLenum, const char*>	errorMessages(codes, messages);

    return errorMessages[code];
}

}
}
