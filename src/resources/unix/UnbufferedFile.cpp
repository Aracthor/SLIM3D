#include "slim/debug/SyscallException.hh"

#include <unistd.h>

namespace slim
{
namespace resources
{

UnbufferedFile::UnbufferedFile(const char* name) :
    File(name)
{
}

UnbufferedFile::~UnbufferedFile() noexcept(false)
{
    SLIM_DEBUG_SYSCALL_CALL(close(m_fd));
}

}
}
