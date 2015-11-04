#ifndef SLIM_TIME_SLEEPER_HPP_
# define SLIM_TIME_SLEEPER_HPP_

# include <ctime>

namespace slim
{
namespace time
{

class	Sleeper
{
public:
    Sleeper();
    ~Sleeper();

public:
    void    sleep(time_t seconds);
    void    usleep(time_t microseconds);
};

}
}

#endif // !SLIM_TIME_SLEEPER_HPP_