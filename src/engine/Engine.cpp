#include <iostream> // Only to print exception error message

#include "slim/assets/Manager.hpp"
#include "slim/attributes.h"
#include "slim/debug/LogManager.hpp"
#include "slim/engine/Engine.hpp"
#include "slim/io/macros.h"
#include "slim/memory/Manager.hpp"
#include "slim/maths/Helper.hpp"
#include "slim/string.h"

namespace slim
{
namespace engine
{

Engine::Engine(int argc, char** argv) :
    m_gameplayLoop(this),
    m_renderLoop(this)
{
    this->addModule<memory::Manager>();
    this->addModule<debug::LogManager>();
    this->addModule<MathsHelper>();
    this->addModule<assets::Manager>();

    this->parseCommandLine(argc, argv);
}

Engine::~Engine()
{
}


void
Engine::parseCommandLine(int argc, char** argv)
{
    containers::Buffer<char, 0x1000>	buffer;
    char*				path = strrchr(argv[0], SLIM_IO_SEPARATOR_CHAR);

    if (path == nullptr)
    {
	buffer << '.' << SLIM_IO_SEPARATOR_CHAR << '\0';
    }
    else
    {
	*path = '\0';
	buffer << argv[0] << '\0';
    }

    assets::Manager::instance.setExecutablePath(buffer.getData());
    debug::LogManager::instance.setExecutablePath(buffer.getData());

    SLIM_CORE_USE(argc);
    // TODO parse command line for real.
}

void
Engine::onInit()
{
    // Empty by default, should be overriden by user.
}

void
Engine::onUpdate(SLIM_CORE_UNUSED(time::Clock::time, elapsedTime))
{
    // Empty by default, should be overriden by user.
}

void
Engine::onShutdown()
{
    // Empty by default, should be overriden by user.
}


void
Engine::start()
{
    this->init();
    this->loop();
    this->shutdown();
}


void
Engine::init()
{
    m_running = true;

    m_singletonsManager.initSingletons();
    m_memory = &memory::Manager::instance.createChunk<memory::ArenaChunk>(SLIM_ENGINE_CORE_MEMORY_SIZE, "engine core");
    m_window = m_memory->create<window::WindowImplementation>(m_windowParameters);
    m_context = m_memory->create<graphics::Context>(m_window);
    m_eventsLoop.setWindow(m_window);

    // Add default loops.
    m_synchronizer.addLoop(&m_gameplayLoop);
    m_synchronizer.addLoop(&m_renderLoop);
    m_synchronizer.addLoop(&m_eventsLoop);
    m_synchronizer.restart();

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
    if (m_sceneManager.getCurrentScene() != nullptr)
    {
	m_sceneManager.getCurrentScene()->update(elapsedTime);
    }
    this->onUpdate(elapsedTime);
}

void
Engine::render() const
{
    const scene::Scene*	scene = m_sceneManager.getCurrentScene();

    if (scene != nullptr)
    {
	scene->display();
    }
    m_window->display();
}

void
Engine::shutdown()
{
    if (m_window)
    {
	m_memory->destroy(m_context);
	m_memory->destroy(m_window);
    }
    m_sceneManager.deleteAllScenes();
    m_singletonsManager.destroySingletons();
}

}
}
