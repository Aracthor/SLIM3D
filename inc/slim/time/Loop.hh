//
// Loop.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 17:12:13 2015 Aracthor
// Last Update Sat Sep 12 17:17:29 2015 Aracthor
//

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
