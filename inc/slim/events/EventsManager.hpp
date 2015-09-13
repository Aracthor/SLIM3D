//
// EventsManager.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 20:19:38 2015 Aracthor
// Last Update Sun Sep 13 09:13:19 2015 Aracthor
//

namespace slim
{
namespace events
{

void
EventsManager::addKeyListener(IKeyListener* listener, keyboard::EKeyCode keyCode)
{
    m_keyListeners[keyCode].push_back(listener);
}

void
EventsManager::addKeyPressListener(IKeyListener* listener, keyboard::EKeyCode keyCode)
{
    m_keyPressListeners[keyCode].push_back(listener);
}

void
EventsManager::addKeyReleaseListener(IKeyListener* listener, keyboard::EKeyCode keyCode)
{
    m_keyReleaseListeners[keyCode].push_back(listener);
}

void
EventsManager::addMouseButtonListener(IMouseListener* listener, mouse::EButton button)
{
    m_mouseButtonListeners[button].push_back(listener);
}

void
EventsManager::addMouseButtonPressListener(IMouseListener* listener, mouse::EButton button)
{
    m_mouseButtonPressListeners[button].push_back(listener);
}

void
EventsManager::addMouseButtonReleaseListener(IMouseListener* listener, mouse::EButton button)
{
    m_mouseButtonReleaseListeners[button].push_back(listener);
}

void
EventsManager::addMouseMovementListener(IMouseListener* listener)
{
    m_mouseMovementListeners.push_back(listener);
}


template <class T>
void
EventsManager::deleteListeners(std::vector<T*>* listeners, unsigned int number)
{
    for (unsigned int i = 0; i < number; ++i)
    {
	core::delete_content(listeners[i]);
    }
}

}
}
