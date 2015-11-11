#include "slim/debug/LogManager.hpp"

#include "CloseListener.hpp"
#include "HelloWorldScene.hpp"

HelloWorldScene::HelloWorldScene(int argc, char** argv) :
    slim::engine::Engine(argc, argv)
{
    m_windowParameters.width = 800;
    m_windowParameters.height = 600;
    m_windowParameters.fullscreen = false;
    m_windowParameters.title = "SLIM3D samples - hello world scene";
}

HelloWorldScene::~HelloWorldScene()
{
}

void
HelloWorldScene::onInit()
{
    slim::scene::Manager&	manager = this->getSceneManager();
    slim::scene::Scene*		scene = manager.createBlankScene("Test scene");

    manager.setCurrentScene(scene);

    this->getCurrentWindow()->getEventsManager().addCloseListener(new CloseListener(this));
    this->getCurrentWindow()->getEventsManager().addKeyPressListener(new CloseListener(this), slim::events::keyboard::escape);
}

void
HelloWorldScene::onUpdate(slim::time::Clock::time elapsed)
{
    (void)elapsed;
}
