#include "slim/time/Loop.hh"

namespace slim
{
namespace time
{

Loop::Loop(unsigned int framerate) :
    m_accumulated(0)
{
    this->setFramerate(framerate);
}

Loop::~Loop()
{
}


void
Loop::setFramerate(unsigned int framerate)
{
    m_framerate = framerate;
    m_timeToWait = 1000000 / m_framerate;
}

void
Loop::addTime(Clock::time elapsedTime)
{
    m_accumulated += elapsedTime;
    if (m_accumulated > m_timeToWait)
    {
	this->onFrame(m_accumulated);
	m_accumulated = 0;
    }
}

}
}
