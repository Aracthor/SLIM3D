//
// IEventListener.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 19:56:00 2015 Aracthor
// Last Update Sat Sep 12 19:56:34 2015 Aracthor
//

#ifndef SLIM_EVENTS_IEVENT_LISTENER_HH_
# define SLIM_EVENTS_IEVENT_LISTENER_HH_

namespace slim
{
namespace events
{

class	IEventListener
{
public:
    virtual ~IEventListener() {}

public:
    virtual void	onEvent() = 0;
};

}
}

#endif // !SLIM_EVENTS_IEVENT_LISTENER_HH_
