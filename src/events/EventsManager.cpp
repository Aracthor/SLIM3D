//
// EventsManager.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 20:19:28 2015 Aracthor
// Last Update Sat Sep 12 22:47:41 2015 Aracthor
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
    	m_keyListeners[key] = EventListenersPack();
    	m_keyPressListeners[key] = EventListenersPack();
	m_keyReleaseListeners[key] = EventListenersPack();
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
	EventListenersPack& listeners = m_keyPressListeners[keyCode];
	listeners.onEvent();
    }
    else if (action == keyboard::released)
    {
	m_keysCurrentlyPressed[keyCode] = false;
	EventListenersPack& listeners = m_keyReleaseListeners[keyCode];
	listeners.onEvent();
    }
}


void
EventsManager::manage()
{
    for (unsigned int key = 0; key < keyboard::keysNumber; key++)
    {
	if (m_keysCurrentlyPressed[key])
	{
	    m_keyListeners[key].onEvent();
	}
    }
}

}
}
