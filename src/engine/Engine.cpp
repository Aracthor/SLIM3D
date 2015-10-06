#include <exception>
#include <iostream> // Only to print exception error message

#include "slim/assets/Manager.hpp"
#include "slim/assets/Image.hpp"
#include "slim/context/Context.hpp"
#include "slim/attributes.h"
#include "slim/debug/LogManager.hpp"
#include "slim/engine/Engine.hpp"
#include "slim/io/macros.h"
#include "slim/maths/Helper.hpp"
#include "slim/shader/Program.hpp"
#include "slim/shader/Shader.hpp"

#include <cstring>

namespace slim
{
namespace engine
{

Engine::Engine(int argc, char** argv) :
    m_gameplayLoop(this),
    m_renderLoop(this)
{
    this->addModule<debug::LogManager>();
    this->addModule<MathsHelper>();
    this->addModule<assets::Manager>();
    this->addModule<context::Context>();

    this->parseCommandLine(argc, argv);
}

Engine::~Engine()
{
}


void
Engine::parseCommandLine(int argc, char** argv)
{
    char*	path = strrchr(argv[0], SLIM_IO_SEPARATOR_CHAR);

    if (path == nullptr)
    {
	containers::Buffer<char, 0x10>	buffer;
	buffer << '.' << SLIM_IO_SEPARATOR_CHAR << '\0';
	assets::Manager::instance.setExecutablePath(buffer.getData());
    }
    else
    {
	*path = '\0';
	assets::Manager::instance.setExecutablePath(argv[0]);
    }

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
    m_running = true;

    m_singletonsManager.initSingletons();
    m_window = new window::WindowImplementation(m_windowParameters);

    // Add default loops.
    m_synchronizer.addLoop(&m_gameplayLoop);
    m_synchronizer.addLoop(&m_renderLoop);
    m_synchronizer.addLoop(&m_window->getEventsLoop());
    m_synchronizer.restart();

    // Add default asset types.
    assets::Manager::instance.registerAssetType<assets::Image>();
    assets::Manager::instance.registerAssetType<shader::Shader>();
    assets::Manager::instance.registerAssetType<shader::Program>();

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
}

}
}
