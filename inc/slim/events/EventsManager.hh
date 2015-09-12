//
// EventsManager.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 20:19:08 2015 Aracthor
// Last Update Sat Sep 12 22:40:17 2015 Aracthor
//

#ifndef SLIM_EVENTS_EVENTS_MANAGER_HH_
# define SLIM_EVENTS_EVENTS_MANAGER_HH_

# include "slim/containers/PresizedArray.hh"
# include "slim/events/EventListenersPack.hh"
# include "slim/events/keyboard.hh"
# include "slim/events/mouse.hh"

namespace slim
{
namespace events
{

class	EventsManager
{
public:
    EventsManager();
    ~EventsManager();

public:
    void	onKeyAction(keyboard::EKeyCode keyCode, int scancode, keyboard::EAction action, int modifiers);
    void	onMouseButtonAction(mouse::EButton button, mouse::EAction action, int modifiers);
    void	onMouseMovement(double x, double y);

public:
    inline void	addKeyListener(IEventListener* listener, keyboard::EKeyCode keyCode);
    inline void	addKeyPressListener(IEventListener* listener, keyboard::EKeyCode keyCode);
    inline void	addKeyReleaseListener(IEventListener* listener, keyboard::EKeyCode keyCode);

public:
    void	manage();

private:
    bool		m_keysCurrentlyPressed[keyboard::keysNumber];
    EventListenersPack	m_keyListeners[keyboard::keysNumber];
    EventListenersPack	m_keyPressListeners[keyboard::keysNumber];
    EventListenersPack	m_keyReleaseListeners[keyboard::keysNumber];
};

}
}

# include "EventsManager.hpp"

#endif // !SLIM_EVENTS_EVENTS_MANAGER_HH_
