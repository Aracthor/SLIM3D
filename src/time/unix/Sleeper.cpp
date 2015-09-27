#include "slim/debug/SyscallException.hh"

#include <unistd.h>

namespace slim
{
namespace time
{

Sleeper::Sleeper()
{
}

Sleeper::~Sleeper()
{
}

void
Sleeper::usleep(time_t microseconds)
{
    SLIM_DEBUG_SYSCALL_CALL(::usleep(microseconds));
}

void
Sleeper::sleep(time_t seconds)
{
    if (::sleep(seconds) != 0)
    {
	throw debug::SyscallException("Sleep interrupted", __FILE__, __func__, __LINE__);
    }
}

}
}
