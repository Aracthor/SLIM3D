//
// LogManager.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:04:35 2015 Aracthor
// Last Update Thu Sep  3 23:11:57 2015 Aracthor
//

#include "slim3d/debug/LogManager.hh"

namespace slim
{
namespace debug
{

LogManager
LogManager::instance;


LogManager::LogManager() :
    m_logs({Log("resources")}),
    resources(m_logs[0])
{
}

LogManager::~LogManager()
{
}


void
LogManager::init()
{
    time::Date			now;
    char			dirName[SLIM3D_DEBUG_LOG_NAME_BUFFER_SIZE];

    now.toFormat(dirName, SLIM3D_DEBUG_LOG_NAME_BUFFER_SIZE, "%d-%m-%Y_%H:%M:%S");

    resources::Directory	directory(dirName);

    for (Log& log : m_logs)
    {
	log.init(directory);
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
