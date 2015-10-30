#ifndef SLIM_EVENTS_IKEY_LISTENER_HPP_
# define SLIM_EVENTS_IKEY_LISTENER_HPP_

namespace slim
{
namespace events
{

class	IKeyListener
{
public:
    virtual ~IKeyListener() {}

public:
    virtual void	onEvent() = 0;
};

}
}

#endif // !SLIM_EVENTS_IKEY_LISTENER_HPP_
