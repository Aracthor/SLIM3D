//
// EventsManager.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 20:19:08 2015 Aracthor
// Last Update Sun Sep 13 09:14:46 2015 Aracthor
//

#ifndef SLIM_EVENTS_EVENTS_MANAGER_HH_
# define SLIM_EVENTS_EVENTS_MANAGER_HH_

# include <vector> // TODO implement our own.

# include "slim/containers/PresizedArray.hh"
# include "slim/events/IKeyListener.hh"
# include "slim/events/IMouseListener.hh"
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
    inline void	addKeyListener(IKeyListener* listener, keyboard::EKeyCode keyCode);
    inline void	addKeyPressListener(IKeyListener* listener, keyboard::EKeyCode keyCode);
    inline void	addKeyReleaseListener(IKeyListener* listener, keyboard::EKeyCode keyCode);

    inline void	addMouseButtonListener(IMouseListener* listener, mouse::EButton button);
    inline void	addMouseButtonPressListener(IMouseListener* listener, mouse::EButton button);
    inline void	addMouseButtonReleaseListener(IMouseListener* listener, mouse::EButton button);
    inline void	addMouseMovementListener(IMouseListener* listener);

public:
    void	manage();

private:
    template <class T>
    void	deleteListeners(std::vector<T*>* listeners, unsigned int number);

private:
    maths::Vector2d			m_currentMousePosition;

    bool				m_keysCurrentlyPressed[keyboard::keysNumber];
    std::vector<IKeyListener*>		m_keyListeners[keyboard::keysNumber];
    std::vector<IKeyListener*>		m_keyPressListeners[keyboard::keysNumber];
    std::vector<IKeyListener*>		m_keyReleaseListeners[keyboard::keysNumber];

    bool				m_mouseButtonsCurrentlyPressed[mouse::buttonsNumber];
    std::vector<IMouseListener*>	m_mouseButtonListeners[mouse::buttonsNumber];
    std::vector<IMouseListener*>	m_mouseButtonPressListeners[mouse::buttonsNumber];
    std::vector<IMouseListener*>	m_mouseButtonReleaseListeners[mouse::buttonsNumber];
    std::vector<IMouseListener*>	m_mouseMovementListeners;
};

}
}

# include "EventsManager.hpp"

#endif // !SLIM_EVENTS_EVENTS_MANAGER_HH_
