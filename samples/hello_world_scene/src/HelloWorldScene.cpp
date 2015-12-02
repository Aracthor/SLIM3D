#include "slim/camera/FreeFly.hpp"
#include "slim/camera/Node.hpp"
#include "slim/debug/LogManager.hpp"
#include "slim/memory/Manager.hpp"
#include "slim/mesh/Mesh.hpp"
#include "slim/mesh/Node.hpp"

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

    slim::memory::ArenaChunk&	chunk = slim::memory::Manager::instance.createChunk<slim::memory::ArenaChunk>(10000, "assets");
    slim::mesh::Mesh*		cube = slim::assets::Asset::create<slim::mesh::Mesh>(chunk, "cube.obj");
    slim::camera::Camera*	camera = chunk.create<slim::camera::FreeFly>();

    scene->getRoot()->addChild<slim::mesh::Node>("mesh test", cube);
    scene->getRoot()->addChild<slim::camera::Node>("camera test", camera);
    scene->setActiveCamera(camera);
    manager.setCurrentScene(scene);

    slim::assets::Manager::instance.loadNeededAssets();

    this->getCurrentWindow()->getEventsManager().addCloseListener(new CloseListener(this));
    this->getCurrentWindow()->getEventsManager().addKeyPressListener(new CloseListener(this), slim::events::keyboard::escape);
}

void
HelloWorldScene::onUpdate(slim::time::Clock::time elapsed)
{
    (void)elapsed;
}
