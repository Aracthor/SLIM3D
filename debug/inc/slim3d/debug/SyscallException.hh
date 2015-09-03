//
// SyscallException.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 17:19:10 2015 Aracthor
// Last Update Thu Sep  3 21:58:10 2015 Aracthor
//

#ifndef SLIM3D_DEBUG_SYSCALL_EXCEPTION_HH_
# define SLIM3D_DEBUG_SYSCALL_EXCEPTION_HH_

# include "slim3d/debug/Exception.hh"

# define SLIM3D_DEBUG_SYSCALL_CALL(syscall)	if ((syscall) == static_cast<int>(-1)) throw slim::debug::SyscallException("SYSCALL FAIL", __FILE__, __func__, __LINE__);
# define SLIM3D_DEBUG_SYSCALL_CALL_PTR(syscall)	if ((syscall) == NULL) throw slim::debug::SyscallException("SYSCALL FAIL", __FILE__, __func__, __LINE__);

namespace slim
{
namespace debug
{

class	SyscallException : public Exception
{
public:
    SyscallException(const char* message, const char* file, const char* function, int line);
    virtual ~SyscallException();

public:
    inline int	getErrnoCode() const;

protected:
    int	m_errno;
};

# include "SyscallException.hpp"

}
}

#endif // !SLIM3D_DEBUG_SYSCALL_EXCEPTION_HH_
