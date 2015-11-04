#include "slim/debug/LogManager.hpp"

#include "CloseListener.hpp"
#include "HelloWorldEngine.hpp"

HelloWorldEngine::HelloWorldEngine(int argc, char** argv) :
    slim::engine::Engine(argc, argv)
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
    this->getCurrentWindow()->getEventsManager().addKeyPressListener(new CloseListener(this), slim::events::keyboard::escape);
}

void
HelloWorldEngine::onUpdate(slim::time::Clock::time elapsed)
{
    slim::debug::LogManager::instance.graphics.info << elapsed << slim::debug::LogStream::endline;
}
