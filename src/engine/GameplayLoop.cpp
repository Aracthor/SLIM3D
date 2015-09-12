//
// GameplayLoop.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 18:09:52 2015 Aracthor
// Last Update Sat Sep 12 18:26:24 2015 Aracthor
//

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
