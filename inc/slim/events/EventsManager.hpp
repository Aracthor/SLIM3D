//
// EventsManager.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 20:19:38 2015 Aracthor
// Last Update Sat Sep 12 21:10:51 2015 Aracthor
//

namespace slim
{
namespace events
{

void
EventsManager::addKeyListener(IEventListener* listener, keyboard::EKeyCode keyCode)
{
    m_keyListeners[keyCode].push_back(listener);
}

void
EventsManager::addKeyPressListener(IEventListener* listener, keyboard::EKeyCode keyCode)
{
    m_keyPressListeners[keyCode].push_back(listener);
}

void
EventsManager::addKeyReleaseListener(IEventListener* listener, keyboard::EKeyCode keyCode)
{
    m_keyReleaseListeners[keyCode].push_back(listener);
}

}
}
