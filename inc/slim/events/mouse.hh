//
// mouse.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 20:11:54 2015 Aracthor
// Last Update Sun Sep 13 00:30:23 2015 Aracthor
//

#ifndef SLIM_EVENTS_MOUSE_HH_
# define SLIM_EVENTS_MOUSE_HH_

# include <GLFW/glfw3.h>

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
