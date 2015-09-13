#include "slim/core/Singleton.hh"

namespace slim
{
namespace core
{

Singleton::Singleton() :
    m_inited(false)
{
}

Singleton::~Singleton()
{
}


void
Singleton::init()
{
    m_inited = true;
    this->onInit();
}

void
Singleton::destroy()
{
    m_inited = false;
    this->onDestroy();
}

}
}
