#ifndef SLIM_EVENTS_MOUSE_BUTTON_CONVERTER_HPP_
# define SLIM_EVENTS_MOUSE_BUTTON_CONVERTER_HPP_

# include <map> // TODO create our own

# include "slim/events/mouse.hpp"

namespace slim
{
namespace events
{

class	MouseButtonConverter
{
public:
    MouseButtonConverter();
    ~MouseButtonConverter();

public:
    inline mouse::EButton	convert(unsigned int button);

private:
    std::map<unsigned int, mouse::EButton>	m_buttons;
};

}
}

# include "MouseButtonConverter.ipp"

#endif // !SLIM_EVENTS_MOUSE_BUTTON_CONVERTER_HPP_
