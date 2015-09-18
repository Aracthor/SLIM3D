#include "slim/core/attributes.h"
#include "slim/engine/glfw.h"
#include "slim/events/EventsLoop.hh"

namespace slim
{
namespace events
{

EventsLoop::EventsLoop(EventsManager& eventsManager) :
    time::Loop(SLIM_EVENTS_DEFAULT_EVENTS_FRAMERATE),
    m_eventsManager(eventsManager)
{
}

EventsLoop::~EventsLoop()
{
}


void
EventsLoop::onFrame(SLIM_CORE_UNUSED(time::Clock::time, elapsedTime))
{
    glfwPollEvents();
}

}
}
