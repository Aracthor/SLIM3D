#include "slim/core/SingletonsManager.hh"
#include "slim/debug/LogManager.hh"
#include "slim/maths/Helper.hh"
#include "slim/window/MonitorsManager.hh"

namespace slim
{
namespace core
{

SingletonsManager::SingletonsManager()
{
    this->listSingletons();
    this->initSingletons();
}

SingletonsManager::~SingletonsManager()
{
    this->destroySingletons();
}


void
SingletonsManager::listSingletons()
{
    m_singletons[0] = &debug::LogManager::instance;
    m_singletons[1] = &MathsHelper::instance;
    m_singletons[2] = &window::MonitorsManager::instance;
}

void
SingletonsManager::initSingletons()
{
    for (Singleton* singleton : m_singletons)
    {
	singleton->init();
    }
}

void
SingletonsManager::destroySingletons()
{
    for (int i = SINGLETONS_NUMBER - 1; i >= 0; --i)
    {
	m_singletons[i]->destroy();
    }
}

}
}
