namespace slim
{
namespace scene
{

const char*
Scene::getName() const
{
    return m_name;
}

const RootNode*
Scene::getRoot() const
{
    return m_root;
}

RootNode*
Scene::getRoot()
{
    return m_root;
}

}
}
