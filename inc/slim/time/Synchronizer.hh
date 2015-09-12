//
// Synchronizer.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 16:09:53 2015 Aracthor
// Last Update Sat Sep 12 21:19:23 2015 Aracthor
//

#ifndef SLIM_TIME_SYNCHRONIZER_HH_
# define SLIM_TIME_SYNCHRONIZER_HH_

# include "slim/containers/PresizedArray.hh"
# include "slim/time/Clock.hh"
# include "slim/time/Loop.hh"

# define SLIM_TIME_LOOPS_NUMBER	3

namespace slim
{
namespace time
{

class	Synchronizer
{
public:
    Synchronizer();
    ~Synchronizer();

public:
    inline void	restart();
    inline void	addLoop(Loop* loop);
    void	nextFrame();

private:
    inline Clock::time	getMinimumRemainingTime() const;

private:
    Clock       m_clock;
    containers::PresizedArray<Loop*, SLIM_TIME_LOOPS_NUMBER>	m_loops;
};

}
}

# include "Synchronizer.hpp"

#endif // !SLIM_TIME_SYNCHRONIZER_HH_
