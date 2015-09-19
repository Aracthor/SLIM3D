#include "slim/engine/Engine.hh"
#include "slim/events/ICloseListener.hh"

class CloseListener : public slim::events::ICloseListener
{
public:
    CloseListener(slim::engine::Engine* engine);

public:
    void onEvent() override;

private:
    slim::engine::Engine*	m_engine;
};
