#include <typeinfo>

#include "slim/containers/Buffer.hh"
#include "slim/core/SingletonsManager.hh"

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
	containers::Buffer<char, 0x200>	buffer;

	buffer << "Trying to add singleton " << typeid(*singleton).name() << " after SingletonManager initialization." << '\0';
	throw debug::Exception(buffer.getData(), __FILE__, __func__, __LINE__);
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
