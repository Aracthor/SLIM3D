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
ListenersManager::onLoad(const Asset* asset)
{
    SLIM_DEBUG_ASSERT(m_listenerLists.count(asset->getType()) != 0);

    m_listenerLists[asset->getType()]->onLoad(asset);
}

}
}
