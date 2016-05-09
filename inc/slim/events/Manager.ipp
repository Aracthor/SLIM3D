#include "slim/debug/assert.hpp"

namespace slim
{
namespace events
{

template <class LISTENER, class PARAM>
void
Manager::addKeyListener(PARAM& param, keyboard::EKeyCode keyCode)
{
    SLIM_DEBUG_ASSERT(!m_keyListeners[keyCode]);
    m_keyListeners[keyCode] = m_memory.create<LISTENER>(param);
}

template <class LISTENER, class PARAM>
void
Manager::addKeyPressListener(PARAM& param, keyboard::EKeyCode keyCode)
{
    SLIM_DEBUG_ASSERT(!m_keyPressListeners[keyCode]);
    m_keyPressListeners[keyCode] = m_memory.create<LISTENER>(param);
}

template <class LISTENER, class PARAM>
void
Manager::addKeyReleaseListener(PARAM& param, keyboard::EKeyCode keyCode)
{
    SLIM_DEBUG_ASSERT(!m_keyReleaseListeners[keyCode]);
    m_keyReleaseListeners[keyCode] = m_memory.create<LISTENER>(param);
}


template <class LISTENER, class PARAM>
void
Manager::addMouseButtonListener(PARAM& param, mouse::EButton button)
{
    SLIM_DEBUG_ASSERT(!m_mouseButtonListeners[button]);
    m_mouseButtonListeners[button] = m_memory.create<LISTENER>(param);
}

template <class LISTENER, class PARAM>
void
Manager::addMouseButtonPressListener(PARAM& param, mouse::EButton button)
{
    SLIM_DEBUG_ASSERT(!m_mouseButtonPressListeners[button]);
    m_mouseButtonPressListeners[button] = m_memory.create<LISTENER>(param);
}

template <class LISTENER, class PARAM>
void
Manager::addMouseButtonReleaseListener(PARAM& param, mouse::EButton button)
{
    SLIM_DEBUG_ASSERT(!m_mouseButtonReleaseListeners[button]);
    m_mouseButtonReleaseListeners[button] = m_memory.create<LISTENER>(param);
}

template <class LISTENER, class PARAM>
void
Manager::addMouseMovementListener(PARAM& param)
{
    SLIM_DEBUG_ASSERT(!m_mouseMovementListener);
    m_mouseMovementListener = m_memory.create<LISTENER>(param);
}

template <class LISTENER, class PARAM>
void
Manager::addCloseListener(PARAM& param)
{
    SLIM_DEBUG_ASSERT(!m_closeListener);
    m_closeListener = m_memory.create<LISTENER>(param);
}


void
Manager::setNextMouseMovementForced()
{
    m_nextMouseMovementForced = true;
}


bool
Manager::isKeyPressed(keyboard::EKeyCode key) const
{
    return m_keysCurrentlyPressed[key];
}

bool
Manager::isMouseButtonPressed(mouse::EButton button) const
{
    return m_mouseButtonsCurrentlyPressed[button];
}

}
}
