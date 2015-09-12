//
// Loop.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 17:12:26 2015 Aracthor
// Last Update Sat Sep 12 17:27:15 2015 Aracthor
//

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
