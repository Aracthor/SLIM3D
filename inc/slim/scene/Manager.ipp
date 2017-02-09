namespace slim
{
namespace scene
{

Scene*
Manager::createBlankScene(const char* name)
{
    return m_scenes.create(name);
}

void
Manager::deleteScene(Scene* scene)
{
    m_scenes.destroy(*scene);
}

void
Manager::deleteAllScenes()
{
    m_scenes.clear();
}


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

}
}
