#ifndef SLIM_CLOCK_TIME_HH_
# define SLIM_CLOCK_TIME_HH_

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

#endif // !SLIM_CLOCK_TIME_HH_