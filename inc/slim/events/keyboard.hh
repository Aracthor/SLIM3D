#ifndef SLIM_EVENTS_KEYBOARD_HH_
# define SLIM_EVENTS_KEYBOARD_HH_

# include <GLFW/glfw3.h>

namespace slim
{
namespace events
{

namespace keyboard
{

enum	EKeyCode
    {
	unknown		= GLFW_KEY_UNKNOWN,
	space		= GLFW_KEY_SPACE,
	apostrophe	= GLFW_KEY_APOSTROPHE,
	comma		= GLFW_KEY_COMMA,
	minus		= GLFW_KEY_MINUS,
	period		= GLFW_KEY_PERIOD,
	slash		= GLFW_KEY_SLASH,
	zero		= GLFW_KEY_0,
	one		= GLFW_KEY_1,
	two		= GLFW_KEY_2,
	three		= GLFW_KEY_3,
	four		= GLFW_KEY_4,
	five		= GLFW_KEY_5,
	six		= GLFW_KEY_6,
	seven		= GLFW_KEY_7,
	eight		= GLFW_KEY_8,
	nine		= GLFW_KEY_9,
	semicolon	= GLFW_KEY_SEMICOLON,
	equal		= GLFW_KEY_EQUAL,
	a		= GLFW_KEY_A,
	b		= GLFW_KEY_B,
	c		= GLFW_KEY_C,
	d		= GLFW_KEY_D,
	e		= GLFW_KEY_E,
	f		= GLFW_KEY_F,
	g		= GLFW_KEY_G,
	h		= GLFW_KEY_H,
	i		= GLFW_KEY_I,
	j		= GLFW_KEY_J,
	k		= GLFW_KEY_K,
	l		= GLFW_KEY_L,
	m		= GLFW_KEY_M,
	n		= GLFW_KEY_N,
	o		= GLFW_KEY_O,
	p		= GLFW_KEY_P,
	q		= GLFW_KEY_Q,
	r		= GLFW_KEY_R,
	s		= GLFW_KEY_S,
	t		= GLFW_KEY_T,
	u		= GLFW_KEY_U,
	v		= GLFW_KEY_V,
	w		= GLFW_KEY_W,
	x		= GLFW_KEY_X,
	y		= GLFW_KEY_Y,
	z		= GLFW_KEY_Z,
	leftBracket	= GLFW_KEY_LEFT_BRACKET,
	backslash	= GLFW_KEY_BACKSLASH,
	rightBracket	= GLFW_KEY_RIGHT_BRACKET,
	graveAccent	= GLFW_KEY_GRAVE_ACCENT,

	escape		= GLFW_KEY_ESCAPE,
	enter		= GLFW_KEY_ENTER,
	tab		= GLFW_KEY_TAB,
	backspace	= GLFW_KEY_BACKSPACE,
	insert		= GLFW_KEY_INSERT,
	delet		= GLFW_KEY_DELETE,
	right		= GLFW_KEY_RIGHT,
	left		= GLFW_KEY_LEFT,
	down		= GLFW_KEY_DOWN,
	up		= GLFW_KEY_UP,
	f01		= GLFW_KEY_F1,
	f02		= GLFW_KEY_F2,
	f03		= GLFW_KEY_F3,
	f04		= GLFW_KEY_F4,
	f05		= GLFW_KEY_F5,
	f06		= GLFW_KEY_F6,
	f07		= GLFW_KEY_F7,
	f08		= GLFW_KEY_F8,
	f09		= GLFW_KEY_F9,
	f10		= GLFW_KEY_F10,
	f11		= GLFW_KEY_F11,
	f12		= GLFW_KEY_F12,
	leftShift	= GLFW_KEY_LEFT_SHIFT,
	leftControl	= GLFW_KEY_LEFT_CONTROL,
	leftAlt		= GLFW_KEY_LEFT_ALT,
	leftSuper	= GLFW_KEY_LEFT_SUPER,
	rightShift	= GLFW_KEY_RIGHT_SHIFT,
	rightControl	= GLFW_KEY_RIGHT_CONTROL,
	rightAlt        = GLFW_KEY_RIGHT_ALT,
	rightSuper	= GLFW_KEY_RIGHT_SUPER,

	keysNumber
    };

enum	EAction
    {
	pressed		= GLFW_PRESS,
	released	= GLFW_RELEASE,
	repeat		= GLFW_REPEAT
    };
}

}
}

#endif // !SLIM_EVENTS_KEYBOARD_HH_
