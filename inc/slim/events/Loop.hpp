#ifndef SLIM_EVENTS_LOOP_HPP_
# define SLIM_EVENTS_LOOP_HPP_

# include "slim/engine/GameplayLoop.hpp"
# include "slim/time/Loop.hpp"
# include "slim/window/Window.hpp"

# define SLIM_EVENTS_DEFAULT_EVENTS_FRAMERATE	(SLIM_ENGINE_DEFAULT_GAMEPLAY_FRAMERATE * 2)

namespace slim
{
namespace events
{

class			Loop : public time::Loop
{
public:
    Loop();
    ~Loop();

public:
    inline void		setWindow(window::Window* window);

protected:
    void		onFrame(time::Clock::time elapsedTime) override;

private:
    window::Window*	m_window = nullptr;
};

}
}

# include "Loop.ipp"

#endif // !SLIM_EVENTS_LOOP_HPP_
