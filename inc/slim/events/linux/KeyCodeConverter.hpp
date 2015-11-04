#ifndef SLIM_EVENTS_LINUX_KEY_CODE_CONVERTER_HPP_
# define SLIM_EVENTS_LINUX_KEY_CODE_CONVERTER_HPP_

# include <map> // TODO use our own

# include "slim/events/keyboard.hpp"

namespace slim
{
namespace events
{

class	KeyCodeConverter
{
public:
    KeyCodeConverter();
    ~KeyCodeConverter();

public:
    inline keyboard::EKeyCode	convert(unsigned int XCode);

private:
    std::map<unsigned int, keyboard::EKeyCode>	m_codes;
};

}
}

# include "KeyCodeConverter.ipp"

#endif // !SLIM_EVENTS_LINUX_KEY_CODE_CONVERTER_HPP_
