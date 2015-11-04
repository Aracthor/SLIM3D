#ifndef SLIM_EVENTS_MANAGER_HPP_
# define SLIM_EVENTS_MANAGER_HPP_

# include "slim/events/IListener.hpp"
# include "slim/events/IMouseListener.hpp"
# include "slim/events/keyboard.hpp"
# include "slim/events/mouse.hpp"

namespace slim
{
namespace events
{

class	Manager
{
public:
    Manager();
    ~Manager();

public:
    void	onKeyPressed(keyboard::EKeyCode keyCode);
    void	onKeyReleased(keyboard::EKeyCode keyCode);
    void	onMouseButtonPressed(mouse::EButton button);
    void	onMouseButtonReleased(mouse::EButton button);
    void	onMouseMovement(double x, double y);
    void	onClose();

public:
    inline void	addKeyPressListener(IListener* listener, keyboard::EKeyCode keyCode);
    inline void	addKeyReleaseListener(IListener* listener, keyboard::EKeyCode keyCode);

    inline void	addMouseButtonPressListener(IMouseListener* listener, mouse::EButton button);
    inline void	addMouseButtonReleaseListener(IMouseListener* listener, mouse::EButton button);
    inline void	addMouseMovementListener(IMouseListener* listener);

    inline void	addCloseListener(IListener* listener);

    inline bool	isKeyPressed(keyboard::EKeyCode key) const;
    inline bool	isMouseButtonPressed(mouse::EButton button) const;

private:
    template <class T>
    void	deleteListeners(T** listeners, unsigned int number);

private:
    maths::Vector2d	m_currentMousePosition;

    bool		m_keysCurrentlyPressed[keyboard::keysMax];
    IListener*		m_keyPressListeners[keyboard::keysMax];
    IListener*		m_keyReleaseListeners[keyboard::keysMax];

    bool		m_mouseButtonsCurrentlyPressed[mouse::buttonsMax];
    IMouseListener*	m_mouseButtonPressListeners[mouse::buttonsMax];
    IMouseListener*	m_mouseButtonReleaseListeners[mouse::buttonsMax];
    IMouseListener*	m_mouseMovementListener;

    IListener*		m_closeListener;
};

}
}

# include "Manager.ipp"

#endif // !SLIM_EVENTS_MANAGER_HPP_
