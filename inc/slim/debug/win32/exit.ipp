#include "slim/windows.h"

namespace slim
{
namespace debug
{

template <typename ...Args>
void
windowsExit(const char* message, const char* file, const char* func, int line, Args&& ...args)
{
    char    buffer[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

    // Thanks to humbagumba for this creepy but working code.
    ::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,    // It´s a system error
		    nullptr,    // No string to be formatted needed
		    GetLastError(),    // Hey Windows: Please explain this error!
		    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),  // Do it in the standard language
		    buffer,    // Put the message here
		    sizeof(buffer) - 1,    // Number of bytes to store the message
		    nullptr);
    exit(buffer, file, func, line, args...);
}

}
}
