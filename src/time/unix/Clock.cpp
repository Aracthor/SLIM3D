#include "slim/debug/SyscallException.hpp"

#include <sys/time.h>

namespace slim
{
namespace time
{

Clock::time
Clock::getCurrentTime() const
{
    struct timeval	tv;

    SLIM_DEBUG_SYSCALL_CALL(gettimeofday(&tv, nullptr));

    return (tv.tv_usec + tv.tv_sec * 1000000);
}

}
}
