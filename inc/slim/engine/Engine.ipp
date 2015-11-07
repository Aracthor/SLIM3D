namespace slim
{
namespace engine
{

void
Engine::stop()
{
    m_running = false;
}


unsigned int
Engine::getGameplayFramerate() const
{
    return m_gameplayLoop.getFramerate();
}

unsigned int
Engine::getRenderFramerate() const
{
    return m_renderLoop.getFramerate();
}

window::Window*
Engine::getCurrentWindow()
{
    return m_window;
}

scene::Scene*
Engine::getCurrentScene()
{
    return m_currentScene;
}


void
Engine::setGameplayFramerate(unsigned int framerate)
{
    m_gameplayLoop.setFramerate(framerate);
}

void
Engine::setRenderFramerate(unsigned int framerate)
{
    m_renderLoop.setFramerate(framerate);
}


template <class Singleton>
void
Engine::addModule()
{
    m_singletonsManager.addSingleton(&Singleton::instance);
}


bool
Engine::isRunning() const
{
    return m_running;
}

}
}
