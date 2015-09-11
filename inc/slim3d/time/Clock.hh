//
// Clock.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/time
// 
// Made by Aracthor
// 
// Started on  Wed Sep  9 10:41:59 2015 Aracthor
// Last Update Wed Sep  9 10:56:55 2015 Aracthor
//

#ifndef SLIM3D_CLOCK_TIME_HH_
# define SLIM3D_CLOCK_TIME_HH_

namespace slim
{
namespace time
{

class	Clock
{
public:
    typedef unsigned long	time;

public:
    Clock();
    ~Clock();

public:
    void	update();
    time	reset();

public:
    inline bool	isRunning() const;
    inline time	getElapsedTime() const;

public:
    inline void	setRunning(bool running);

private:
    time	getCurrentTime() const;

private:
    bool	m_running;
    time	m_start;
    time	m_elapsedTime;
};

}
}

# include "Clock.hpp"

#endif // !SLIM3D_CLOCK_TIME_HH_
