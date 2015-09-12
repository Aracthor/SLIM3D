//
// EventListenersPack.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 22:41:25 2015 Aracthor
// Last Update Sat Sep 12 22:41:55 2015 Aracthor
//

namespace slim
{
namespace events
{

void
EventListenersPack::add(IEventListener* listener)
{
    m_listeners.push_back(listener);
}

}
}
