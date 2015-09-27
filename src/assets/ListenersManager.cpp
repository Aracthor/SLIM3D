#include "slim/assets/Asset.hh"
#include "slim/assets/ListenersManager.hh"
#include "slim/debug/assert.hh"
#include "slim/debug/LogManager.hh" // debug

namespace slim
{
namespace assets
{

ListenersManager::ListenersManager()
{
}

ListenersManager::~ListenersManager()
{
}


void
ListenersManager::addAsset(const Asset* asset)
{
    SLIM_DEBUG_ASSERT(m_listenerLists.count(asset->getType()) != 0);
    m_listenerLists[asset->getType()][asset] = std::vector<Listener*>();
}

void
ListenersManager::addListener(Listener* listener, const Asset* asset)
{
    SLIM_DEBUG_ASSERT(m_listenerLists.count(asset->getType()) != 0);
    SLIM_DEBUG_ASSERT(m_listenerLists[asset->getType()].count(asset) != 0);
    m_listenerLists[asset->getType()][asset].push_back(listener);
}


void
ListenersManager::onLoad(const Asset* asset)
{
    SLIM_DEBUG_ASSERT(m_listenerLists.count(asset->getType()) != 0);
    SLIM_DEBUG_ASSERT(m_listenerLists[asset->getType()].count(asset) != 0);
    for (Listener* listener : m_listenerLists[asset->getType()][asset])
    {
	listener->onOneAssetReady();
    }
}

void
ListenersManager::onUnload(const Asset* asset)
{
    SLIM_DEBUG_ASSERT(m_listenerLists.count(asset->getType()) != 0);
    SLIM_DEBUG_ASSERT(m_listenerLists[asset->getType()].count(asset) != 0);
    for (Listener* listener : m_listenerLists[asset->getType()][asset])
    {
	listener->onOneAssetUnloaded();
    }
}

}
}
