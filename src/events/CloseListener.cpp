#include "slim/events/CloseListener.hpp"

namespace slim
{
namespace events
{

CloseListener::CloseListener(engine::Engine& engine) :
    m_engine(engine)
{
}

void
CloseListener::onEvent()
{
    m_engine.stop();
}

}
}
