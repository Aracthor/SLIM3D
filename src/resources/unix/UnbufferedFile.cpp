#include "slim/debug/SyscallException.hh"

#include <unistd.h>

namespace slim
{
namespace resources
{

UnbufferedFile::UnbufferedFile()
{
}

UnbufferedFile::~UnbufferedFile() noexcept(false)
{
    SLIM_DEBUG_SYSCALL_CALL(close(m_fd));
}

}
}
