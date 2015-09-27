namespace slim
{
namespace assets
{

void
Manager::addListener(Listener* listener, const Asset* asset)
{
    m_listenersManager.addListener(listener, asset);
}


template <class ASSET>
void
Manager::registerAsset(ASSET* asset)
{
    m_listenersManager.addAsset(asset);
    this->addToLoadList(asset);
}

template <class ASSET>
void
Manager::registerAssetType()
{
    m_listenersManager.registerAssetType<ASSET>();
}

}
}
