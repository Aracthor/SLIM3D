//
// LogManager.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:04:35 2015 Aracthor
// Last Update Mon Aug 31 23:49:51 2015 Aracthor
//

#include "slim3d/debug/LogManager.hh"

namespace slim
{
namespace debug
{

LogManager
LogManager::instance;


void
LogManager::init()
{
    for (Log& log : m_logs)
    {
	log.init();
    }
}

void
LogManager::destroy()
{
    for (Log& log : m_logs)
    {
	log.destroy();
    }
}

}
}
