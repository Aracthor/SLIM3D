//
// Singleton.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 15:53:56 2015 Aracthor
// Last Update Sat Sep 12 16:00:22 2015 Aracthor
//

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
