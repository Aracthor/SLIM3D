#include "slim/events/linux/MouseButtonConverter.hpp"

#include <X11/Xlib.h>

namespace slim
{
namespace events
{

MouseButtonConverter::MouseButtonConverter()
{
    m_buttons[Button1] = mouse::buttonLeft;
    m_buttons[Button2] = mouse::buttonMiddle;
    m_buttons[Button3] = mouse::buttonRight;
}

MouseButtonConverter::~MouseButtonConverter()
{
}

}
}
