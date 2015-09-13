//
// IKeyListener.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 19:56:00 2015 Aracthor
// Last Update Sun Sep 13 00:22:31 2015 Aracthor
//

#ifndef SLIM_EVENTS_IKEY_LISTENER_HH_
# define SLIM_EVENTS_IKEY_LISTENER_HH_

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

#endif // !SLIM_EVENTS_IKEY_LISTENER_HH_
