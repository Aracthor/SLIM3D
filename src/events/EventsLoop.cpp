//
// EventsLoop.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 19:34:13 2015 Aracthor
// Last Update Sat Sep 12 21:05:01 2015 Aracthor
//

#include "slim/core/attributes.h"
#include "slim/events/EventsLoop.hh"

#include <GLFW/glfw3.h>

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
EventsLoop::onFrame(SLIM_CORE_UNUSED time::Clock::time elapsedTime)
{
    glfwPollEvents();
    m_eventsManager.manage();
}

}
}
