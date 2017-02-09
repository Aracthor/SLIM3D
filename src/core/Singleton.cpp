#include "slim/core/Singleton.hpp"

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


bool
Singleton::init()
{
    m_inited = true;
    return this->onInit();
}

void
Singleton::destroy()
{
    m_inited = false;
    this->onDestroy();
}

}
}
