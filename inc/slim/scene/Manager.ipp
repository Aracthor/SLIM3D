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
    return m_scenes.destroy(*scene);
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
