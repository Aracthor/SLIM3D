//
// Synchronizer.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 16:09:53 2015 Aracthor
// Last Update Sat Sep 12 17:54:45 2015 Aracthor
//

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

    m_clock.update();

    elapsed = m_clock.getElapsedTime();
    remaining = this->getMinimumRemainingTime();
    if (remaining > elapsed)
    {
	SLIM_DEBUG_SYSCALL_CALL(usleep(remaining - elapsed));
	elapsed = remaining;
    }

    m_loops.forEach(&addTime, elapsed);

    m_clock.reset();
}

}
}
