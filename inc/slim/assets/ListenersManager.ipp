#include "slim/debug/assert.hpp"

namespace slim
{
namespace assets
{

template <class ASSET>
void
ListenersManager::registerAssetType()
{
    SLIM_DEBUG_ASSERT(m_listenerLists.count(ASSET::typeName) == 0);

    m_listenerLists[ASSET::typeName] = ListenerList();
}

}
}
