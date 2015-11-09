namespace slim
{
namespace scene
{

const Scene*
Manager::getCurrentScene() const
{
    return m_currentScene;
}

Scene*
Manager::getCurrentScene()
{
    return m_currentScene;
}

void
Manager::setCurrentScene(Scene* scene)
{
    m_currentScene = scene;
}

}
}
