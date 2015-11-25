#include <typeinfo>

#include "slim/core/SingletonsManager.hpp"
#include "slim/debug/exit.hpp"

namespace slim
{
namespace core
{

SingletonsManager::SingletonsManager() :
    m_inited(false)
{
}

SingletonsManager::~SingletonsManager()
{
}


void
SingletonsManager::addSingleton(Singleton* singleton)
{
    if (m_inited)
    {
	SLIM_DEBUG_EXIT("Trying to add singleton ", typeid(*singleton).name(), " after SingletonsManager initialization.");
    }
    m_singletons.push_back(singleton);
}


void
SingletonsManager::initSingletons()
{
    unsigned int	i;

    m_inited = true;
    for (i = 0; i < m_singletons.size(); i++)
    {
	m_singletons[i]->init();
    }
}

void
SingletonsManager::destroySingletons()
{
    int	i;

    m_inited = false;
    for (i = m_singletons.size() - 1; i >= 0; i--)
    {
	m_singletons[i]->destroy();
    }
    m_singletons.clear();
}

}
}
