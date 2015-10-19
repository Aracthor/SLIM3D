#include "slim/debug/exit.hpp"
#include "slim/debug/syscall.hpp"

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
	SLIM_DEBUG_EXIT("Sleep interrupted");
    }
}

}
}
