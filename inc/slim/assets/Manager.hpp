namespace slim
{
namespace assets
{

template <class ASSET>
void
Manager::registerAsset(const ASSET* asset)
{
    m_listenersManager.addAsset(asset);
}

template <class ASSET>
void
Manager::registerAssetType()
{
    m_listenersManager.registerAssetType<ASSET>();
}

}
}
