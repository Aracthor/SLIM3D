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
	SLIM_DEBUG_EXIT("Trying to add singleton ", typeid(*singleton).name(), " after SingletonManager initialization.");
    }
    m_singletons.push_back(singleton);
}


void
SingletonsManager::initSingletons()
{
    m_inited = true;
    for (Singleton* singleton : m_singletons)
    {
	singleton->init();
    }
}

void
SingletonsManager::destroySingletons()
{
    m_inited = false;
    for (Singleton* singleton : m_singletons)
    {
	singleton->destroy();
    }
    m_singletons.clear();
}

}
}
