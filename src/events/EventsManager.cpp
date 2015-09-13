//
// EventsManager.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 20:19:28 2015 Aracthor
// Last Update Sun Sep 13 09:14:32 2015 Aracthor
//

#include "slim/core/attributes.h"
#include "slim/core/templates.hh"
#include "slim/events/EventsManager.hh"

#include <cstring>

namespace slim
{
namespace events
{

EventsManager::EventsManager()
{
    memset(m_keysCurrentlyPressed, false, sizeof(m_keysCurrentlyPressed));
    memset(m_mouseButtonsCurrentlyPressed, false, sizeof(m_mouseButtonsCurrentlyPressed));
}

EventsManager::~EventsManager()
{
    this->deleteListeners(m_keyListeners, keyboard::keysNumber);
    this->deleteListeners(m_keyPressListeners, keyboard::keysNumber);
    this->deleteListeners(m_keyReleaseListeners, keyboard::keysNumber);

    this->deleteListeners(m_mouseButtonListeners, mouse::buttonsNumber);
    this->deleteListeners(m_mouseButtonPressListeners, mouse::buttonsNumber);
    this->deleteListeners(m_mouseButtonReleaseListeners, mouse::buttonsNumber);
    core::delete_content(m_mouseMovementListeners);
}


void
EventsManager::onKeyAction(keyboard::EKeyCode keyCode, SLIM_CORE_UNUSED int scancode,
			   keyboard::EAction action, SLIM_CORE_UNUSED int modifiers)
{
    if (action == keyboard::pressed)
    {
	m_keysCurrentlyPressed[keyCode] = true;
	for (IKeyListener* listener : m_keyPressListeners[keyCode])
	{
	    listener->onEvent();
	}
    }
    else if (action == keyboard::released)
    {
	m_keysCurrentlyPressed[keyCode] = false;
	for (IKeyListener* listener : m_keyReleaseListeners[keyCode])
	{
	    listener->onEvent();
	}
    }
}

void
EventsManager::onMouseButtonAction(mouse::EButton button, mouse::EAction action, SLIM_CORE_UNUSED int modifiers)
{
    if (action == mouse::pressed)
    {
	m_mouseButtonsCurrentlyPressed[button] = true;
	for (IMouseListener* listener : m_mouseButtonPressListeners[button])
	{
	    listener->onEvent(m_currentMousePosition);
	}
    }
    else if (action == mouse::released)
    {
	m_mouseButtonsCurrentlyPressed[button] = false;
	for (IMouseListener* listener : m_mouseButtonReleaseListeners[button])
	{
	    listener->onEvent(m_currentMousePosition);
	}
    }
}

void
EventsManager::onMouseMovement(double x, double y)
{
    m_currentMousePosition.x = x;
    m_currentMousePosition.y = y;
    for (IMouseListener* listener : m_mouseMovementListeners)
    {
	listener->onEvent(m_currentMousePosition);
    }
}


void
EventsManager::manage()
{
    for (unsigned int key = 0; key < keyboard::keysNumber; key++)
    {
	if (m_keysCurrentlyPressed[key])
	{
	    for (IKeyListener* listener : m_keyListeners[key])
	    {
		listener->onEvent();
	    }
	}
    }

    for (unsigned int button = 0; button < mouse::buttonsNumber; button++)
    {
	if (m_mouseButtonsCurrentlyPressed[button])
	{
	    for (IMouseListener* listener : m_mouseButtonListeners[button])
	    {
		listener->onEvent(m_currentMousePosition);
	    }
	}
    }
}

}
}
