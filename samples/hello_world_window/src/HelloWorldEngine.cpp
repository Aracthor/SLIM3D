#include "CLoseListener.hh"
#include "HelloWorldEngine.hh"

HelloWorldEngine::HelloWorldEngine()
{
    m_windowParameters.title = "SLIM3D samples - hello world window";
}

HelloWorldEngine::~HelloWorldEngine()
{
}


void
HelloWorldEngine::onInit()
{
    this->getCurrentWindow()->getEventsManager().addCloseListener(new CloseListener(this));
}