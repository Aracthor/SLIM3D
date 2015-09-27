namespace slim
{
namespace assets
{

void
Manager::addToLoadList(Asset* asset)
{
    m_assets[asset->getType()].push_back(asset);
}

ListenersManager&
Manager::getListenersManager()
{
    return m_listenersManager;
}

}
}
