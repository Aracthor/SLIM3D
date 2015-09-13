#include <exception>
#include <iostream> // Only to print exception error message

#include "slim/core/attributes.h"
#include "slim/engine/Engine.hh"

namespace slim
{
namespace engine
{

Engine::Engine() :
    m_gameplayLoop(this),
    m_renderLoop(this)
{
}

Engine::~Engine()
{
}


void
Engine::onInit()
{
    // Empty by default, should be overriden by user.
}

void
Engine::onUpdate(SLIM_CORE_UNUSED time::Clock::time elapsedTime)
{
    // Empty by default, should be overriden by user.
}


void
Engine::start()
{
    try
    {
	this->init();
	this->loop();
    }
    catch (const std::exception& exception)
    {
	std::cerr << exception.what() << std::endl;
    }
    this->shutdown();
}


void
Engine::init()
{
    m_singletonsManager = new core::SingletonsManager();
    m_window = new window::Window(m_windowParameters);
    m_synchronizer.addLoop(&m_gameplayLoop);
    m_synchronizer.addLoop(&m_renderLoop);
    m_synchronizer.addLoop(&m_window->getEventsLoop());
    m_synchronizer.restart();
    m_running = true;

    this->onInit(); // Implemented by user
}

void
Engine::loop()
{
    while (this->isRunning())
    {
	m_synchronizer.nextFrame();
    }
}

void
Engine::update(time::Clock::time elapsedTime)
{
    this->onUpdate(elapsedTime);
}

void
Engine::render() const
{
    m_window->display();
}

void
Engine::shutdown()
{
    if (m_window)
    {
	delete m_window;
    }
    if (m_singletonsManager)
    {
	delete m_singletonsManager;
    }
}

}
}
