#ifndef SLIM_DEBUG_WINDOWS_EXCEPTION_HH_
# define SLIM_DEBUG_WINDOWS_EXCEPTION_HH_

# include "slim/debug/Exception.hh"

namespace slim
{
namespace debug
{

class WindowsException : public Exception
{
public:
    static void	throws(const char* file, const char* function, int line);

private:
    WindowsException(const char* message, const char* file, const char* function, int line);
    ~WindowsException() throw();
};

}
}

#endif // !SLIM_DEBUG_WINDOWS_EXCEPTION_HH_
