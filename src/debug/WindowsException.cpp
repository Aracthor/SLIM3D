#include "slim/debug/WindowsException.hh"

namespace slim
{
namespace debug
{

SLIM_CORE_NORETURN void
WindowsException::throws(const char* file, const char* func, int line)
{
    char    buffer[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

    // Thanks to humbagumba for this creepy but working code.
    ::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,	    // It´s a system error
	nullptr,				    // No string to be formatted needed
	GetLastError(),				    // Hey Windows: Please explain this error!
	MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),  // Do it in the standard language
	buffer,					    // Put the message here
	sizeof(buffer) - 1,			    // Number of bytes to store the message
	nullptr);
    throw WindowsException(buffer, file, func, line);
}


WindowsException::WindowsException(const char* message, const char* file, const char* func, int line) :
    Exception(message, file, func, line)
{
}

WindowsException::~WindowsException() throw()
{
}

}
}