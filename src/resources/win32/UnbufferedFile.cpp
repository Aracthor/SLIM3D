#include "slim/debug/SyscallException.hh"

#include <Windows.h>

namespace slim
{
namespace resources
{

UnbufferedFile::UnbufferedFile(const char* name) :
    File(name)
{
}

UnbufferedFile::~UnbufferedFile()
{
    SLIM_DEBUG_SYSCALL_CALL(CloseHandle(m_fd));
}

}
}
