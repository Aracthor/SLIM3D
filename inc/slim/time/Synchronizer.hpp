//
// Synchronizer.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 16:09:53 2015 Aracthor
// Last Update Sat Sep 12 17:59:46 2015 Aracthor
//

namespace slim
{
namespace time
{

void
Synchronizer::restart()
{
    m_clock.reset();
}

void
Synchronizer::addLoop(Loop* loop)
{
    m_loops.insert(loop);
}


static Clock::time
getRemainingTime(Loop* const& loop)
{
    return loop->getRemainingTime();
}

Clock::time
Synchronizer::getMinimumRemainingTime() const
{
    return m_loops.minimum(&getRemainingTime);
}

}
}
