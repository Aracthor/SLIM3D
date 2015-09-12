//
// EventsLoop.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 19:34:13 2015 Aracthor
// Last Update Sat Sep 12 21:03:52 2015 Aracthor
//

#ifndef SLIM_EVENTS_EVENTS_LOOP_HH_
# define SLIM_EVENTS_EVENTS_LOOP_HH_

# include "slim/engine/GameplayLoop.hh"
# include "slim/events/EventsManager.hh"
# include "slim/time/Loop.hh"

# define SLIM_EVENTS_DEFAULT_EVENTS_FRAMERATE	(SLIM_ENGINE_DEFAULT_GAMEPLAY_FRAMERATE * 2)

namespace slim
{
namespace events
{

class		EventsLoop : public time::Loop
{
public:
    EventsLoop(EventsManager& eventsManager);
    ~EventsLoop();

protected:
    void	onFrame(time::Clock::time elapsedTime) override;

private:
    EventsManager&	m_eventsManager;
};

}
}

#endif // !SLIM_EVENTS_EVENTS_LOOP_HH_
