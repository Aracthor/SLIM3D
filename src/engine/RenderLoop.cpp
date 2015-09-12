//
// RenderLoop.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 18:08:22 2015 Aracthor
// Last Update Sat Sep 12 18:25:21 2015 Aracthor
//

#include "slim/core/attributes.h"
#include "slim/engine/Engine.hh"
#include "slim/engine/RenderLoop.hh"

namespace slim
{
namespace engine
{

RenderLoop::RenderLoop(const Engine* engine) :
    time::Loop(SLIM_ENGINE_DEFAULT_RENDER_FRAMERATE),
    m_engine(engine)
{
}

RenderLoop::~RenderLoop()
{
}


void
RenderLoop::onFrame(SLIM_CORE_UNUSED time::Clock::time elapsedTime)
{
    m_engine->render();
}

}
}
