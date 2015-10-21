#include "slim/debug/LogManager.hpp"
#include "slim/io/macros.h"

namespace slim
{
namespace debug
{

LogManager
LogManager::instance;


LogManager::LogManager() :
    FileAccesser(SLIM_DEBUG_LOGS_FOLDER),
    m_logs{
    Log("assets"),
    Log("graphics")},
    assets(m_logs[0]),
    graphics(m_logs[1])
{
}

LogManager::~LogManager()
{
}


bool
LogManager::onInit()
{
    time::Date					        now;
    char						buffer[SLIM_CORE_MAX_PATH_SIZE];
    containers::Buffer<char, SLIM_CORE_MAX_PATH_SIZE>	dirName;

    now.toFormat(buffer, SLIM_CORE_MAX_PATH_SIZE, "%d-%m-%Y_%H-%M-%S");

    dirName << m_path;
    dirName << buffer << SLIM_IO_SEPARATOR_CHAR << '\0';

    io::Directory	rootDirectory(m_path.getData());
    io::Directory	directory(dirName.getData());

    for (Log& log : m_logs)
    {
	log.init(directory);
    }

    return true; // TODO check
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
