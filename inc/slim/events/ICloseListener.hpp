#ifndef SLIM_EVENTS_ICLOSE_LISTENER_HPP_
# define SLIM_EVENTS_ICLOSE_LISTENER_HPP_

namespace slim
{
namespace events
{

class	ICloseListener
{
public:
    virtual ~ICloseListener() {}

public:
    virtual void	onEvent() = 0;
};

}
}

#endif // !SLIM_EVENTS_ICLOSE_LISTENER_HPP_
