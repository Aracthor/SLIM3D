#include "slim/debug/SyscallException.hh"

#include <cstdlib>
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
    SLIM_DEBUG_SYSCALL_CALL(usleep(microseconds));
}

void
Sleeper::sleep(time_t seconds)
{
    SLIM_DEBUG_SYSCALL_CALL(sleep(seconds));
}

}
}
