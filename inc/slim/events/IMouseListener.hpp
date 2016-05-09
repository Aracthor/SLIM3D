#ifndef SLIM_EVENTS_IMOUSE_LISTENER_HPP_
# define SLIM_EVENTS_IMOUSE_LISTENER_HPP_

# include "slim/events/mouse.hpp"
# include "slim/maths/Vector2.hpp"

namespace slim
{
namespace events
{

class	IMouseListener
{
public:
    virtual ~IMouseListener() {}

public:
    virtual void	onEvent(const Vector2& position) = 0;
};

}
}

#endif // !SLIM_EVENTS_IMOUSE__LISTENER_HPP_
