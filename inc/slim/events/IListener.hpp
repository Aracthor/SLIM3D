#ifndef SLIM_EVENTS_I_LISTENER_HPP_
# define SLIM_EVENTS_I_LISTENER_HPP_

namespace slim
{
namespace events
{

class	IListener
{
public:
    virtual ~IListener() {}

public:
    virtual void	onEvent() = 0;
};

}
}

#endif // !SLIM_EVENTS_I_LISTENER_HPP_
