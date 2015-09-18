#ifndef SLIM_DEBUG_WINDOWS_EXCEPTION_HH_
# define SLIM_DEBUG_WINDOWS_EXCEPTION_HH_

# include "slim/core/attributes.h"
# include "slim/debug/Exception.hh"

# include <Windows.h>

# define SLIM_DEBUG_WINDOWS_SYSCALL_CALL(syscall)	if ((syscall) == FALSE) slim::debug::WindowsException::throws(__FILE__, __func__, __LINE__);
# define SLIM_DEBUG_WINDOWS_SYSCALL_CALL_PTR(syscall)	if ((syscall) == nullptr) slim::debug::WindowsException::throws(__FILE__, __func__, __LINE__);

namespace slim
{
namespace debug
{

class	WindowsException : public Exception
{
public:
    SLIM_CORE_NORETURN static void	throws(const char* file, const char* function, int line);

private:
    WindowsException(const char* message, const char* file, const char* function, int line);
    ~WindowsException() throw();
};

}
}

#endif // !SLIM_DEBUG_WINDOWS_EXCEPTION_HH_
