#include "slim/attributes.h"
#include "slim/events/Manager.hpp"
#include "slim/memory/Manager.hpp"

#include "slim/string.h" // For memset

namespace slim
{
namespace events
{

Manager::Manager() :
    m_currentMousePosition(0, 0),
    m_memory(memory::Manager::instance.createChunk<ChunkType>(SLIM_EVENTS_MANAGER_MEMORY, "Events manager"))
{
    // Set every listener to nullptr.
    memset(m_keysCurrentlyPressed, 0, sizeof(m_keysCurrentlyPressed));
    memset(m_keyListeners, 0, sizeof(m_keyListeners));
    memset(m_keyPressListeners, 0, sizeof(m_keyPressListeners));
    memset(m_keyReleaseListeners, 0, sizeof(m_keyReleaseListeners));

    memset(m_mouseButtonsCurrentlyPressed, 0, sizeof(m_mouseButtonsCurrentlyPressed));
    memset(m_mouseButtonListeners, 0, sizeof(m_mouseButtonListeners));
    memset(m_mouseButtonPressListeners, 0, sizeof(m_mouseButtonPressListeners));
    memset(m_mouseButtonReleaseListeners, 0, sizeof(m_mouseButtonReleaseListeners));
    m_nextMouseMovementForced = false;
    m_mouseMovementListener = nullptr;

    m_closeListener = nullptr;
}

Manager::~Manager()
{
}


void
Manager::onKeyPressed(keyboard::EKeyCode keyCode)
{
    m_keysCurrentlyPressed[keyCode] = true;
    if (m_keyPressListeners[keyCode])
    {
	m_keyPressListeners[keyCode]->onEvent();
    }
}

void
Manager::onKeyReleased(keyboard::EKeyCode keyCode)
{
    m_keysCurrentlyPressed[keyCode] = false;
    if (m_keyReleaseListeners[keyCode])
    {
	m_keyReleaseListeners[keyCode]->onEvent();
    }
}

void
Manager::onMouseButtonPressed(mouse::EButton button)
{
    m_mouseButtonsCurrentlyPressed[button] = true;
    if (m_mouseButtonPressListeners[button])
    {
	m_mouseButtonPressListeners[button]->onEvent(m_currentMousePosition);
    }
}

void
Manager::onMouseButtonReleased(mouse::EButton button)
{
    m_mouseButtonsCurrentlyPressed[button] = false;
    if (m_mouseButtonReleaseListeners[button])
    {
	m_mouseButtonReleaseListeners[button]->onEvent(m_currentMousePosition);
    }
}

void
Manager::onMouseMovement(double x, double y)
{
    if (m_nextMouseMovementForced)
    {
	m_nextMouseMovementForced = false;
    }
    else
    {
	m_currentMousePosition.x = x;
	m_currentMousePosition.y = y;
	if (m_mouseMovementListener)
	{
	    m_mouseMovementListener->onEvent(m_currentMousePosition);
	}
    }
}

void
Manager::onClose()
{
    if (m_closeListener)
    {
	m_closeListener->onEvent();
    }
}


void
Manager::tickListeners()
{
    unsigned int	i;

    for (i = 0; i < keyboard::keysMax; i++)
    {
	if (m_keysCurrentlyPressed[i] && m_keyListeners[i])
	{
	    m_keyListeners[i]->onEvent();
	}
    }

    for (i = 0; i < mouse::buttonsMax; i++)
    {
	if (m_mouseButtonsCurrentlyPressed[i] && m_mouseButtonListeners[i])
	{
	    m_mouseButtonListeners[i]->onEvent(m_currentMousePosition);
	}
    }
}

}
}
