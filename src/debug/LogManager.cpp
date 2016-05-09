#include "slim/memory/Manager.hpp"
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
    Log("graphics"),
    Log("memory")},
    assets(m_logs[0]),
    graphics(m_logs[1]),
    memory(m_logs[2])
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
    bool						completePath;

    now.toFormat(buffer, SLIM_CORE_MAX_PATH_SIZE, "%d-%m-%Y_%H-%M-%S");

    dirName << m_path;
    dirName << buffer << SLIM_IO_SEPARATOR_CHAR << '\0';
    completePath = (m_path[0] == '/');

    io::Directory	rootDirectory(m_path.getData(), completePath);
    io::Directory	directory(dirName.getData(), completePath);

    for (Log& log : m_logs)
    {
	log.init(directory);
    }

    debug::LogManager::instance.memory.info << "Log manager started, memory initialized with " << memory::Manager::size << " bytes." << debug::LogStream::endline;


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
