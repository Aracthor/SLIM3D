//
// Loop.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 17:12:10 2015 Aracthor
// Last Update Sat Sep 12 22:19:38 2015 Aracthor
//

namespace slim
{
namespace time
{

unsigned int
Loop::getFramerate() const
{
    return m_framerate;
}

Clock::time
Loop::getRemainingTime() const
{
    return (m_timeToWait - m_accumulated);
}

}
}
