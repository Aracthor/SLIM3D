#include "slim/engine/Engine.hpp"
#include "slim/events/ICloseListener.hpp"

class		CloseListener : public slim::events::ICloseListener
{
public:
    CloseListener(slim::engine::Engine* engine);

public:
    void	onEvent() override;

private:
    slim::engine::Engine*	m_engine;
};
