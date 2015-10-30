#include "slim/attributes.h"
#include "slim/events/EventsLoop.hpp"

namespace slim
{
namespace events
{

EventsLoop::EventsLoop(Manager& manager) :
    time::Loop(SLIM_EVENTS_DEFAULT_EVENTS_FRAMERATE),
    m_manager(manager)
{
}

EventsLoop::~EventsLoop()
{
}


void
EventsLoop::onFrame(SLIM_CORE_UNUSED(time::Clock::time, elapsedTime))
{
    // TODO
}

}
}
