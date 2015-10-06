#ifndef SLIM_EVENTS_ICLOSE_LISTENER_HH_
# define SLIM_EVENTS_ICLOSE_LISTENER_HH_

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

#endif // !SLIM_EVENTS_ICLOSE_LISTENER_HH_
