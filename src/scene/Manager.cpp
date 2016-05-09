#include "slim/scene/Manager.hpp"

namespace slim
{
namespace scene
{

Manager::Manager()
{
}

Manager::~Manager()
{
}


void
Manager::setCurrentScene(Scene* scene)
{
    m_currentScene = scene;
    scene->getRoot()->setAssetsNeeded();
}

}
}
