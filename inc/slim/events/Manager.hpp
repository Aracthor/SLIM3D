#ifndef SLIM_EVENTS_MANAGER_HPP_
# define SLIM_EVENTS_MANAGER_HPP_

# include "slim/events/IListener.hpp"
# include "slim/events/IMouseListener.hpp"
# include "slim/events/keyboard.hpp"
# include "slim/events/mouse.hpp"
# include "slim/memory/ArenaChunk.hpp"

# define SLIM_EVENTS_MANAGER_MEMORY	(sizeof(IListener*) * (keyboard::keysMax * 3 + 1) +\
					 sizeof(IMouseListener*) * (mouse::buttonsMax * 3 + 1))

namespace slim
{
namespace events
{

class	Manager
{
private:
    typedef memory::ArenaChunk	ChunkType;


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
    void	tickListeners();

public:
    template <class LISTENER, class PARAM>
    inline void	addKeyListener(PARAM& param, keyboard::EKeyCode keyCode);
    template <class LISTENER, class PARAM>
    inline void	addKeyPressListener(PARAM& param, keyboard::EKeyCode keyCode);
    template <class LISTENER, class PARAM>
    inline void	addKeyReleaseListener(PARAM& param, keyboard::EKeyCode keyCode);

    template <class LISTENER, class PARAM>
    inline void	addMouseButtonListener(PARAM& param, mouse::EButton button);
    template <class LISTENER, class PARAM>
    inline void	addMouseButtonPressListener(PARAM& param, mouse::EButton button);
    template <class LISTENER, class PARAM>
    inline void	addMouseButtonReleaseListener(PARAM& param, mouse::EButton button);
    template <class LISTENER, class PARAM>
    inline void	addMouseMovementListener(PARAM& param);

    template <class LISTENER, class PARAM>
    inline void	addCloseListener(PARAM& param);

    inline void	setNextMouseMovementForced();

    inline bool	isKeyPressed(keyboard::EKeyCode key) const;
    inline bool	isMouseButtonPressed(mouse::EButton button) const;

private:
    Vector2		m_currentMousePosition;

    bool		m_keysCurrentlyPressed[keyboard::keysMax];
    IListener*		m_keyListeners[keyboard::keysMax];
    IListener*		m_keyPressListeners[keyboard::keysMax];
    IListener*		m_keyReleaseListeners[keyboard::keysMax];

    bool		m_mouseButtonsCurrentlyPressed[mouse::buttonsMax];
    IMouseListener*	m_mouseButtonListeners[mouse::buttonsMax];
    IMouseListener*	m_mouseButtonPressListeners[mouse::buttonsMax];
    IMouseListener*	m_mouseButtonReleaseListeners[mouse::buttonsMax];
    bool	        m_nextMouseMovementForced;
    IMouseListener*	m_mouseMovementListener;

    IListener*		m_closeListener;

    memory::Chunk&      m_memory;
};

}
}

# include "Manager.ipp"

#endif // !SLIM_EVENTS_MANAGER_HPP_
