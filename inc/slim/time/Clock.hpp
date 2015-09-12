//
// Clock.hpp for SLIM in /home/aracthor/programs/projects/SLIM/time
// 
// Made by Aracthor
// 
// Started on  Wed Sep  9 10:49:14 2015 Aracthor
// Last Update Wed Sep  9 11:03:16 2015 Aracthor
//

namespace slim
{
namespace time
{

bool
Clock::isRunning() const
{
    return (m_running);
}

Clock::time
Clock::getElapsedTime() const
{
    return (m_elapsedTime);
}


void
Clock::setRunning(bool running)
{
    m_running = running;
}

}
}
