#include "slim/attributes.h"
#include "slim/engine/Engine.hpp"
#include "slim/engine/RenderLoop.hpp"

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
RenderLoop::onFrame(SLIM_CORE_UNUSED(time::Clock::time, elapsedTime))
{
    m_engine->render();
}

}
}
