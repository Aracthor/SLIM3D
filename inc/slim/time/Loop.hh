#ifndef SLIM_TIME_LOOP_HH_
# define SLIM_TIME_LOOP_HH_

# include "slim/time/Clock.hh"

namespace slim
{
namespace time
{

class	Loop
{
public:
    explicit Loop(unsigned int framerate);
    virtual ~Loop();

public:
    void		setFramerate(unsigned int framerate);
    void		addTime(Clock::time elapsedTime);

public:
    inline unsigned int	getFramerate() const;
    inline Clock::time	getRemainingTime() const;

protected:
    virtual void	onFrame(Clock::time elapsedTime) = 0;

private:
    unsigned int	m_framerate;
    Clock::time		m_timeToWait;
    Clock::time		m_accumulated;
};

}
}

# include "Loop.hpp"

#endif // !SLIM_TIME_LOOP_HH_
