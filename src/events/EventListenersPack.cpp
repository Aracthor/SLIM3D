//
// EventListenersPack.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 22:36:35 2015 Aracthor
// Last Update Sat Sep 12 22:47:49 2015 Aracthor
//

#include "slim/events/EventListenersPack.hh"

namespace slim
{
namespace events
{

EventListenersPack::EventListenersPack()
{
}

EventListenersPack::~EventListenersPack()
{
}

void
EventListenersPack::onEvent()
{
    for (IEventListener* listener : m_listeners)
    {
	listener->onEvent();
    }
}

}
}
