#ifndef SLIM_EVENTS_CLOSE_LISTENER_HPP_
# define SLIM_EVENTS_CLOSE_LISTENER_HPP_

# include "slim/engine/Engine.hpp"
# include "slim/events/IListener.hpp"

namespace slim
{

namespace engine
{
class	Engine;
}

namespace events
{

class	CloseListener : public IListener
{
public:
    CloseListener(engine::Engine& engine);

public:
    void onEvent() override;

private:
    engine::Engine&	m_engine;
};

}
}

#endif // !SLIM_EVENTS_CLOSE_LISTENER_HPP_
