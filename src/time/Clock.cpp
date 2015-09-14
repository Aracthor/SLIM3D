#include "slim/debug/SyscallException.hh"
#include "slim/time/Clock.hh"

#include <sys/time.h>

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


Clock::time
Clock::getCurrentTime() const
{
    struct timeval	tv;

    SLIM_DEBUG_SYSCALL_CALL(gettimeofday(&tv, nullptr));

    return (tv.tv_usec + tv.tv_sec * 1000000);
}

}
}