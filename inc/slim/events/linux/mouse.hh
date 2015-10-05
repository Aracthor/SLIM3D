#include <X11/Xlib.h>

namespace slim
{
namespace events
{

namespace mouse
{

enum	EButton
{
    buttonLeft		= Button1,
    buttonMiddle	= Button2,
    buttonRight		= Button3,
    buttonsMax
};

enum	EAction
{
    pressed,
    released
};

}

}
}
