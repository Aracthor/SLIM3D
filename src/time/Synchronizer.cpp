#include "slim/time/Synchronizer.hpp"

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
addTime(Loop*& loop, Clock::time time)
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
	m_sleeper.usleep(remaining - elapsed);
    }

    m_loops.forEach(&addTime, elapsed);
}

}
}
