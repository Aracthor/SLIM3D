#include "slim/core/system.h"
#include "slim/time/Clock.hh"

namespace slim
{
namespace time
{

Clock::Clock() :
    m_running(true)
{
    this->reset();
}

Clock::~Clock()
{
}


void
Clock::update()
{
    if (m_running)
    {
	time	now = this->getCurrentTime();

	m_elapsedTime = now - m_start;
    }
}

Clock::time
Clock::reset()
{
    Clock::time	now = this->getCurrentTime();
    Clock::time	elapsed = now - m_start;

    m_start = now;
    m_elapsedTime = 0;

    return (elapsed);
}

}
}

#if SLIM_CORE_SYSTEM_IS_UNIX
# include "unix/Clock.cpp"
#else
# include "win32/Clock.cpp"
#endif
