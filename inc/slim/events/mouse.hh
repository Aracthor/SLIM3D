#ifndef SLIM_EVENTS_MOUSE_HH_
# define SLIM_EVENTS_MOUSE_HH_

# include "slim/engine/glfw.h"

namespace slim
{
namespace events
{

namespace mouse
{

enum	EButton
{
    buttonLeft	= GLFW_MOUSE_BUTTON_LEFT,
    buttonMiddle	= GLFW_MOUSE_BUTTON_MIDDLE,
    buttonRight	= GLFW_MOUSE_BUTTON_RIGHT,
    buttonsNumber
};

enum	EAction
{
    pressed		= GLFW_PRESS,
    released	= GLFW_RELEASE
};

}

}
}

#endif // !SLIM_EVENTS_MOUSE_HH_
