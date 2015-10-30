#ifndef SLIM_EVENTS_EVENTS_LOOP_HPP_
# define SLIM_EVENTS_EVENTS_LOOP_HPP_

# include "slim/engine/GameplayLoop.hpp"
# include "slim/events/EventsManager.hpp"
# include "slim/time/Loop.hpp"

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

#endif // !SLIM_EVENTS_EVENTS_LOOP_HPP_
