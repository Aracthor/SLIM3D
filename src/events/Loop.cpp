#include "slim/attributes.h"
#include "slim/debug/assert.hpp"
#include "slim/events/Loop.hpp"

namespace slim
{
namespace events
{

Loop::Loop() :
    time::Loop(SLIM_EVENTS_DEFAULT_EVENTS_FRAMERATE)
{
}

Loop::~Loop()
{
}


void
Loop::onFrame(SLIM_CORE_UNUSED(time::Clock::time, elapsedTime))
{
    SLIM_DEBUG_ASSERT(m_window != nullptr);

    m_window->pollEvents();
    m_window->getEventsManager().tickListeners();
}

}
}
