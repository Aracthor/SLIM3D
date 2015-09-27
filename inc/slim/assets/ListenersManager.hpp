#include "slim/assets/ListenerList.hh"
#include "slim/debug/assert.hh"

namespace slim
{
namespace assets
{

template <class ASSET>
void
ListenersManager::registerAssetType()
{
    SLIM_DEBUG_ASSERT(m_listenerLists.count(ASSET::typeName) == 0);

    m_listenerLists[ASSET::typeName] = new ListenerList<ASSET>();
}


template <class ASSET>
void
ListenersManager::addAsset(const ASSET* asset)
{
    ListenerList<ASSET>*	list;

    SLIM_DEBUG_ASSERT(m_listenerLists.count(ASSET::typeName) != 0);
    SLIM_DEBUG_REINTERPRET_CAST(ListenerList<ASSET>*, list, m_listenerLists[ASSET::typeName]);
    list->addAsset(asset);
}

template <class ASSET>
void
ListenersManager::addListener(IListener<ASSET>* listener, const ASSET* asset)
{
    ListenerList<ASSET>*	list;

    SLIM_DEBUG_ASSERT(m_listenerLists.count(ASSET::typeName) != 0);
    SLIM_DEBUG_REINTERPRET_CAST(ListenerList<ASSET>*, list, m_listenerLists[ASSET::typeName]);
    list->addListener(listener, asset);
}

}
}
