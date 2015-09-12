//
// GameplayLoop.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 18:09:52 2015 Aracthor
// Last Update Sat Sep 12 18:26:04 2015 Aracthor
//

#ifndef SLIM_ENGINE_GAMEPLAY_LOOP_HH_
# define SLIM_ENGINE_GAMEPLAY_LOOP_HH_

# include "slim/time/Loop.hh"

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
