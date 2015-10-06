#include "slim/debug/SyscallException.hpp"

#include <unistd.h>

namespace slim
{
namespace io
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
