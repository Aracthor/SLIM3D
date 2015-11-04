#include "slim/attributes.h"
#include "slim/events/Manager.hpp"

#include "slim/string.h" // For memset

namespace slim
{
namespace events
{

Manager::Manager()
{
    memset(this, 0, sizeof(*this));
}

Manager::~Manager()
{
    this->deleteListeners(m_keyPressListeners, keyboard::keysMax);
    this->deleteListeners(m_keyReleaseListeners, keyboard::keysMax);

    this->deleteListeners(m_mouseButtonPressListeners, mouse::buttonsMax);
    this->deleteListeners(m_mouseButtonReleaseListeners, mouse::buttonsMax);
    if (m_mouseMovementListener)
    {
	delete m_mouseMovementListener;
    }

    if (m_closeListener)
    {
	delete m_closeListener;
    }
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
    m_currentMousePosition.x = x;
    m_currentMousePosition.y = y;
    if (m_mouseMovementListener)
    {
	m_mouseMovementListener->onEvent(m_currentMousePosition);
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

}
}
