#include "slim/debug/LogManager.hh"

namespace slim
{
namespace debug
{

LogManager
LogManager::instance;


LogManager::LogManager() :
    m_logs{
    Log("graphics"),
    Log("resources")},
    graphics(m_logs[0]),
    resources(m_logs[1])
{
}

LogManager::~LogManager()
{
}


void
LogManager::onInit()
{
    time::Date			now;
    char			dirName[SLIM_DEBUG_LOG_NAME_BUFFER_SIZE];

    now.toFormat(dirName, SLIM_DEBUG_LOG_NAME_BUFFER_SIZE, "%d-%m-%Y_%H:%M:%S");

    resources::Directory	directory(dirName);

    for (Log& log : m_logs)
    {
	log.init(directory);
    }
}

void
LogManager::onDestroy()
{
    for (Log& log : m_logs)
    {
	log.destroy();
    }
}

}
}
