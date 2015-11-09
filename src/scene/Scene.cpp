#include "slim/memory/Manager.hpp"
#include "slim/scene/Scene.hpp"

namespace slim
{
namespace scene
{

Scene::Scene(const char* name) :
    m_name(name),
    m_memory(memory::Manager::instance.createChunk<SceneChunk>(SLIM_SCENE_MEMORY_SIZE, name)),
    m_root(m_memory.create<RootNode>(m_memory))
{
}

Scene::~Scene()
{
}


void
Scene::update(time::Clock::time elapsedTime)
{
    m_root->update(elapsedTime);
}

}
}
