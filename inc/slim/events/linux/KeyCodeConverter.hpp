#ifndef SLIM_EVENTS_LINUX_KEY_CODE_CONVERTER_HPP_
# define SLIM_EVENTS_LINUX_KEY_CODE_CONVERTER_HPP_

# include <map> // TODO use our own

# include "slim/events/keyboard.hpp"

# include <X11/Xlib.h>

namespace slim
{
namespace events
{

class	KeyCodeConverter
{
public:
    KeyCodeConverter(::Display *& display);
    ~KeyCodeConverter();

public:
    inline keyboard::EKeyCode	convert(unsigned int XCode);

private:
    inline KeySym		convertToKeySym(unsigned int XCode);

private:
    std::map<unsigned int, keyboard::EKeyCode>	m_codes;
    ::Display*&					m_display;
};

}
}

# include "KeyCodeConverter.ipp"

#endif // !SLIM_EVENTS_LINUX_KEY_CODE_CONVERTER_HPP_
