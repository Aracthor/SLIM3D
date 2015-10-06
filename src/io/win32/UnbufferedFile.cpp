#include "slim/debug/SyscallException.hpp"

#include <Windows.h>

namespace slim
{
namespace io
{

UnbufferedFile::UnbufferedFile()
{
}

UnbufferedFile::~UnbufferedFile() noexcept(false)
{
    SLIM_DEBUG_SYSCALL_CALL(CloseHandle(m_fd));
}

}
}
