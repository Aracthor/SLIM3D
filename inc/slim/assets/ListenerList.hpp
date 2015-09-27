#include <algorithm>

namespace slim
{
namespace assets
{

template <class ASSET>
ListenerList<ASSET>::ListenerList()
{
}

template <class ASSET>
ListenerList<ASSET>::~ListenerList()
{
}


template <class ASSET>
const char*
ListenerList<ASSET>::getType() const
{
    return ASSET::typeName;
}


template <class ASSET>
void
ListenerList<ASSET>::addAsset(const ASSET* asset)
{
    SLIM_DEBUG_ASSERT(m_assets.count(asset) == 0);

    m_assets[asset] = std::vector<IListener<ASSET>*>();
}

template <class ASSET>
void
ListenerList<ASSET>::addListener(IListener<ASSET>* listener, const ASSET* asset)
{
    SLIM_DEBUG_ASSERT(m_assets.count(asset) != 0);
    SLIM_DEBUG_ASSERT(std::find(m_assets[asset].begin(), m_assets[asset].end(), listener) == m_assets[asset].end());
    m_assets[asset].push_back(listener);
}

template <class ASSET>
void
ListenerList<ASSET>::onAssetLoad(const ASSET* asset)
{
    SLIM_DEBUG_ASSERT(m_assets.count(asset) != 0);

    for (IListener<ASSET>* listener : m_assets[asset])
    {
	listener->onLoad(asset);
    }
}

}
}
