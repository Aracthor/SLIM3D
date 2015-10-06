#ifndef SLIM_ENGINE_GAMEPLAY_LOOP_HH_
# define SLIM_ENGINE_GAMEPLAY_LOOP_HH_

# include "slim/time/Loop.hpp"

# define SLIM_ENGINE_DEFAULT_GAMEPLAY_FRAMERATE	60

namespace slim
{
namespace engine
{

class	Engine;

class	GameplayLoop : public time::Loop
{
public:
    GameplayLoop(Engine* engine);
    ~GameplayLoop();

protected:
    void	onFrame(time::Clock::time elapsedTime) override;

private:
    Engine*	m_engine;
};

}
}

#endif // !SLIM_ENGINE_GAMEPLAY_LOOP_HH_
