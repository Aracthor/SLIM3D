#ifndef SLIM_EVENTS_I_LISTENER_PACK_HPP_
# define SLIM_EVENTS_I_LISTENER_PACK_HPP_

# include "slim/events/Manager.hpp"

namespace slim
{
namespace events
{

class	IListenerPack
{
public:
    virtual ~IListenerPack() {}

public:
    virtual void	registerEvents(events::Manager& manager) = 0;
};

}
}

#endif // !SLIM_EVENTS_I_LISTENER_PACK_HPP_
