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
