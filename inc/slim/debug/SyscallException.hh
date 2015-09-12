//
// SyscallException.hh for SLIM in /home/aracthor/programs/projects/SLIM/debug
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 17:19:10 2015 Aracthor
// Last Update Thu Sep 10 00:01:04 2015 Aracthor
//

#ifndef SLIM_DEBUG_SYSCALL_EXCEPTION_HH_
# define SLIM_DEBUG_SYSCALL_EXCEPTION_HH_

# include "slim/debug/Exception.hh"

# define SLIM_DEBUG_SYSCALL_CALL(syscall)	if ((syscall) == static_cast<int>(-1)) throw slim::debug::SyscallException("SYSCALL FAIL", __FILE__, __func__, __LINE__);
# define SLIM_DEBUG_SYSCALL_CALL_PTR(syscall)	if ((syscall) == nullptr) throw slim::debug::SyscallException("SYSCALL FAIL", __FILE__, __func__, __LINE__);

namespace slim
{
namespace debug
{

class	SyscallException : public Exception
{
public:
    SyscallException(const char* message, const char* file, const char* function, int line);
    virtual ~SyscallException() throw();

public:
    inline int	getErrnoCode() const;

protected:
    int	m_errno;
};

}
}

# include "SyscallException.hpp"

#endif // !SLIM_DEBUG_SYSCALL_EXCEPTION_HH_
