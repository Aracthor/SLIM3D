#include "slim/debug/assert.hpp"
#include "slim/graphics/FrameRenderer.hpp"
#include "slim/memory/Manager.hpp"
#include "slim/scene/Scene.hpp"

namespace slim
{
namespace scene
{

Scene::Scene(const char* name) :
    m_name(name),
    m_memory(memory::Manager::instance.createChunk<SceneChunk>(SLIM_SCENE_MEMORY_SIZE, name)),
    m_root(m_memory.create<RootNode>(m_memory)),
    m_frameRenderer(m_memory.create<graphics::FrameRenderer>())
{
}

Scene::~Scene()
{
    m_memory.destroy(m_frameRenderer);
}


void
Scene::update(time::Clock::time elapsedTime)
{
    m_root->update(elapsedTime);
}

void
Scene::display() const
{
    SLIM_DEBUG_ASSERT(m_activeCamera != nullptr);

    m_frameRenderer->reset();
    m_frameRenderer->registerCamera(m_activeCamera);
    this->displayNode(m_root);
    m_frameRenderer->draw();
}


void
Scene::displayNode(const Node* node) const
{
    if (dynamic_cast<const mesh::Node*>(node) != nullptr) // TODO better.
    {
	m_frameRenderer->addMesh(*reinterpret_cast<const mesh::Node*>(node));
    }
}

}
}
