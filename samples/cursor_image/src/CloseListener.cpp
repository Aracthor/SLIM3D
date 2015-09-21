#include "CloseListener.hh"

CloseListener::CloseListener(slim::engine::Engine* engine) :
    m_engine(engine)
{
}

void
CloseListener::onEvent()
{
    m_engine->stop();
}
