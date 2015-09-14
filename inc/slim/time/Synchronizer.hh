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
