//
// EventsManager.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 20:19:08 2015 Aracthor
// Last Update Sun Sep 13 09:50:28 2015 Aracthor
//

#ifndef SLIM_EVENTS_EVENTS_MANAGER_HH_
# define SLIM_EVENTS_EVENTS_MANAGER_HH_

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
    inline void	addKeyPressListener(IKeyListener* listener, keyboard::EKeyCode keyCode);
    inline void	addKeyReleaseListener(IKeyListener* listener, keyboard::EKeyCode keyCode);

    inline void	addMouseButtonPressListener(IMouseListener* listener, mouse::EButton button);
    inline void	addMouseButtonReleaseListener(IMouseListener* listener, mouse::EButton button);
    inline void	addMouseMovementListener(IMouseListener* listener);

    inline bool	isKeyPressed(keyboard::EKeyCode key) const;
    inline bool	isMouseButtonPressed(mouse::EButton button) const;

private:
    template <class T>
    void	deleteListeners(T** listeners, unsigned int number);

private:
    maths::Vector2d	m_currentMousePosition;

    bool		m_keysCurrentlyPressed[keyboard::keysNumber];
    IKeyListener*	m_keyPressListeners[keyboard::keysNumber];
    IKeyListener*	m_keyReleaseListeners[keyboard::keysNumber];

    bool		m_mouseButtonsCurrentlyPressed[mouse::buttonsNumber];
    IMouseListener*	m_mouseButtonPressListeners[mouse::buttonsNumber];
    IMouseListener*	m_mouseButtonReleaseListeners[mouse::buttonsNumber];
    IMouseListener*	m_mouseMovementListeners;
};

}
}

# include "EventsManager.hpp"

#endif // !SLIM_EVENTS_EVENTS_MANAGER_HH_
