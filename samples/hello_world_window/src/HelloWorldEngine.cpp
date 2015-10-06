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

#include "slim/context/Context.hpp"
#include "slim/debug/LogManager.hpp"

void
HelloWorldEngine::onInit()
{
    this->getCurrentWindow()->getEventsManager().addCloseListener(new CloseListener(this));
}

void
HelloWorldEngine::onUpdate(slim::time::Clock::time elapsed)
{
    XEvent	event;
    (void)elapsed;

    slim::debug::LogManager::instance.graphics.info << elapsed << slim::debug::LogStream::endline;
    while (XCheckWindowEvent(slim::context::Context::instance.getImplementation()->getDisplay(), dynamic_cast<slim::window::WindowImplementation*>(this->getCurrentWindow())->m_window, 0x00FFFFFF, &event) == 1)
    {
	slim::debug::LogManager::instance.graphics.info << "YOLO " << event.type << slim::debug::LogStream::endline;
    }
}
