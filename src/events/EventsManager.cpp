//
// EventsManager.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 20:19:28 2015 Aracthor
// Last Update Sat Sep 12 22:17:25 2015 Aracthor
//

#include "slim/core/attributes.h"
#include "slim/events/EventsManager.hh"

#include <cstring>

namespace slim
{
namespace events
{

EventsManager::EventsManager()
{
    memset(m_keysCurrentlyPressed, false, sizeof(m_keysCurrentlyPressed));
    for (unsigned int key = 0; key < keyboard::keysNumber; key++)
    {
    	m_keyListeners[key] = std::vector<IEventListener*>();
    	m_keyPressListeners[key] = std::vector<IEventListener*>();
    	m_keyReleaseListeners[key] = std::vector<IEventListener*>();
    }
}

EventsManager::~EventsManager()
{
}


void
EventsManager::onKeyAction(keyboard::EKeyCode keyCode, SLIM_CORE_UNUSED int scancode,
			   keyboard::EAction action, SLIM_CORE_UNUSED int modifiers)
{
    if (action == keyboard::pressed)
    {
	m_keysCurrentlyPressed[keyCode] = true;
	for (IEventListener* listener : m_keyPressListeners[keyCode])
	{
	    listener->onEvent();
	}
    }
    else if (action == keyboard::released)
    {
	m_keysCurrentlyPressed[keyCode] = false;
	for (IEventListener* listener : m_keyReleaseListeners[keyCode])
	{
	    listener->onEvent();
	}
    }
}


void
EventsManager::manage()
{
    for (unsigned int key = 0; key < keyboard::keysNumber; key++)
    {
	if (m_keysCurrentlyPressed[key])
	{
	    for (IEventListener* listener : m_keyListeners[key])
	    {
		listener->onEvent();
	    }
	}
    }
}

}
}
