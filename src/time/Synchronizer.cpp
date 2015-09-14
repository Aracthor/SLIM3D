#include "slim/debug/SyscallException.hh"
#include "slim/time/Synchronizer.hh"

#include <unistd.h>

namespace slim
{
namespace time
{

Synchronizer::Synchronizer()
{
}

Synchronizer::~Synchronizer()
{
}


static void
addTime(Loop*& loop, const Clock::time& time)
{
    loop->addTime(time);
}

void
Synchronizer::nextFrame()
{
    Clock::time	elapsed;
    Clock::time	remaining;

    elapsed = m_clock.reset();

    remaining = this->getMinimumRemainingTime();
    if (remaining > elapsed)
    {
	SLIM_DEBUG_SYSCALL_CALL(usleep(remaining - elapsed));
    }

    m_loops.forEach(&addTime, elapsed);
}

}
}
