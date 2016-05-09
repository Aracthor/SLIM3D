#include "slim/debug/LogManager.hpp"
#include "slim/events/CloseListener.hpp"

#include "HelloWorldWindow.hpp"

HelloWorldWindow::HelloWorldWindow(int argc, char** argv) :
    slim::engine::Engine(argc, argv)
{
    m_windowParameters.width = 800;
    m_windowParameters.height = 600;
    m_windowParameters.fullscreen = false;
    m_windowParameters.title = "SLIM3D samples - hello world window";
}

HelloWorldWindow::~HelloWorldWindow()
{
}

void
HelloWorldWindow::onInit()
{
    this->getCurrentWindow()->getEventsManager().addCloseListener<slim::events::CloseListener>(*this);
    this->getCurrentWindow()->getEventsManager().addKeyPressListener<slim::events::CloseListener>(*this, slim::events::keyboard::escape);
}

void
HelloWorldWindow::onUpdate(slim::time::Clock::time elapsed)
{
    slim::debug::LogManager::instance.graphics.info << elapsed << slim::debug::LogStream::endline;
}
