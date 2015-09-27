#include <algorithm>

#include "slim/debug/assert.hh"

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
ListenerList<ASSET>::onLoad(const Asset* asset)
{
    const ASSET*	convertedAsset;
    SLIM_DEBUG_REINTERPRET_CAST(const ASSET*, convertedAsset, asset);
    SLIM_DEBUG_ASSERT(m_assets.count(convertedAsset) != 0);

    for (IListener<ASSET>* listener : m_assets[convertedAsset])
    {
	listener->onLoad(convertedAsset);
    }
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
    // Check if the asset is registered.
    SLIM_DEBUG_ASSERT(m_assets.count(asset) != 0);
    // Check if the listener is not already registered for this asset.
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
