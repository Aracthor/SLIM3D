#ifndef CLOSE_LISTENER_HH_
# define CLOSE_LISTENER_HH_

# include "slim/engine/Engine.hpp"
# include "slim/events/IListener.hpp"

class CloseListener : public slim::events::IListener
{
public:
    CloseListener(slim::engine::Engine* engine);

public:
    void onEvent() override;

private:
    slim::engine::Engine*	m_engine;
};

#endif // !CLOSE_LISTENER
