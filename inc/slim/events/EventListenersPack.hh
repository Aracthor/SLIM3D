//
// EventListenersPack.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 22:36:39 2015 Aracthor
// Last Update Sat Sep 12 22:41:38 2015 Aracthor
//

#ifndef SLIM_EVENTS_EVENT_LISTENERS_PACK_HH_
# define SLIM_EVENTS_EVENT_LISTENERS_PACK_HH_

# include <vector> // TODO implement our own.

# include "slim/events/IEventListener.hh"

namespace slim
{
namespace events
{

class	EventListenersPack
{
public:
    EventListenersPack();
    ~EventListenersPack();

public:
    void	onEvent();

public:
    inline void	add(IEventListener* listener);

private:
    std::vector<IEventListener*>	m_listeners;
};

}
}

# include "EventListenersPack.hpp"

#endif // !SLIM_EVENTS_EVENT_LISTENERS_PACK_HH_
