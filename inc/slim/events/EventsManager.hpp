#ifndef SLIM_EVENTS_EVENTS_MANAGER_HPP_
# define SLIM_EVENTS_EVENTS_MANAGER_HPP_

# include "slim/events/ICloseListener.hpp"
# include "slim/events/IKeyListener.hpp"
# include "slim/events/IMouseListener.hpp"
# include "slim/events/keyboard.hpp"
# include "slim/events/mouse.hpp"

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
    void	onClose();

public:
    inline void	addKeyPressListener(IKeyListener* listener, keyboard::EKeyCode keyCode);
    inline void	addKeyReleaseListener(IKeyListener* listener, keyboard::EKeyCode keyCode);

    inline void	addMouseButtonPressListener(IMouseListener* listener, mouse::EButton button);
    inline void	addMouseButtonReleaseListener(IMouseListener* listener, mouse::EButton button);
    inline void	addMouseMovementListener(IMouseListener* listener);

    inline void	addCloseListener(ICloseListener* listener);

    inline bool	isKeyPressed(keyboard::EKeyCode key) const;
    inline bool	isMouseButtonPressed(mouse::EButton button) const;

private:
    template <class T>
    void	deleteListeners(T** listeners, unsigned int number);

private:
    maths::Vector2d	m_currentMousePosition;

    bool		m_keysCurrentlyPressed[keyboard::keysMax];
    IKeyListener*	m_keyPressListeners[keyboard::keysMax];
    IKeyListener*	m_keyReleaseListeners[keyboard::keysMax];

    bool		m_mouseButtonsCurrentlyPressed[mouse::buttonsMax];
    IMouseListener*	m_mouseButtonPressListeners[mouse::buttonsMax];
    IMouseListener*	m_mouseButtonReleaseListeners[mouse::buttonsMax];
    IMouseListener*	m_mouseMovementListener;

    ICloseListener*	m_closeListener;
};

}
}

# include "EventsManager.ipp"

#endif // !SLIM_EVENTS_EVENTS_MANAGER_HPP_
