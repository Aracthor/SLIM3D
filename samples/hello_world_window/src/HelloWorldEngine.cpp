#include "CLoseListener.hh"
#include "HelloWorldEngine.hh"

HelloWorldEngine::HelloWorldEngine()
{
    m_windowParameters.width = 800;
    m_windowParameters.height = 600;
    m_windowParameters.fullscreen = false;
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