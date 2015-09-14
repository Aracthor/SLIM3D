#include "slim/engine/Engine.hh"
#include "slim/engine/GameplayLoop.hh"

namespace slim
{
namespace engine
{

GameplayLoop::GameplayLoop(Engine* engine) :
    time::Loop(SLIM_ENGINE_DEFAULT_GAMEPLAY_FRAMERATE),
    m_engine(engine)
{
}

GameplayLoop::~GameplayLoop()
{
}


void
GameplayLoop::onFrame(time::Clock::time elapsedTime)
{
    m_engine->update(elapsedTime);
}

}
}
