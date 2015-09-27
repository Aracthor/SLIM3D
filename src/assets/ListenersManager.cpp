#include "slim/assets/ListenersManager.hh"
#include "slim/core/templates.hh"

namespace slim
{
namespace assets
{

ListenersManager::ListenersManager()
{
}

ListenersManager::~ListenersManager()
{
    for (auto pair : m_listenerLists)
    {
	delete pair.second;
    }
}

}
}
