//
// RenderLoop.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 18:08:22 2015 Aracthor
// Last Update Sat Sep 12 18:22:01 2015 Aracthor
//

#ifndef SLIM_ENGINE_RENDER_LOOP_HH_
# define SLIM_ENGINE_RENDER_LOOP_HH_

# include "slim/time/Loop.hh"

# define SLIM_ENGINE_DEFAULT_RENDER_FRAMERATE	60

namespace slim
{
namespace engine
{

class	Engine;

class	RenderLoop : public time::Loop
{
public:
    RenderLoop(const Engine* engine);
    ~RenderLoop();

protected:
    void		onFrame(time::Clock::time elapsedTime) override;

private:
    const Engine*	m_engine;
};

}
}

#endif // !SLIM_ENGINE_RENDER_LOOP_HH_
