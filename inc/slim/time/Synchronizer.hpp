#ifndef SLIM_TIME_SYNCHRONIZER_HPP_
# define SLIM_TIME_SYNCHRONIZER_HPP_

# include "slim/containers/PresizedArray.hpp"
# include "slim/time/Clock.hpp"
# include "slim/time/Loop.hpp"
# include "slim/time/Sleeper.hpp"

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
    Sleeper	m_sleeper;
    containers::PresizedArray<Loop*, SLIM_TIME_LOOPS_NUMBER>	m_loops;
};

}
}

# include "Synchronizer.ipp"

#endif // !SLIM_TIME_SYNCHRONIZER_HPP_
