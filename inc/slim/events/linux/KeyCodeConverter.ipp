#include <X11/XKBlib.h>

namespace slim
{
namespace events
{

keyboard::EKeyCode
KeyCodeConverter::convert(unsigned int XCode)
{
    return m_codes[this->convertToKeySym(XCode)];
}


KeySym
KeyCodeConverter::convertToKeySym(unsigned int XCode)
{
    return XkbKeycodeToKeysym(m_display, XCode, 0, 0);
}

}
}
