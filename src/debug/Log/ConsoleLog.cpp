#include <iostream>

#include "slim/debug/console.hh"
#include "slim/resources/BufferedWritingFile.hh"

#include <cstring>

namespace slim
{
namespace debug
{

Log::Log(const char* name) :
    LogBase(name)
{
}

Log::~Log()
{
}


void
Log::init(resources::Directory& directory)
{
    char	fileName[SLIM_DEBUG_LOG_NAME_BUFFER_SIZE];

    strncpy(fileName, m_name, SLIM_DEBUG_LOG_NAME_BUFFER_SIZE);
    strncat(fileName, ".slim.log", SLIM_DEBUG_LOG_NAME_BUFFER_SIZE - strlen(m_name));
    m_file = directory.newFile<resources::BufferedWritingFile>(fileName);
}

void
Log::destroy()
{
    delete (m_file);
}



void
Log::write(const char* line, unsigned int size, unsigned int level)
{
    if (level >= m_fileOutputLevel)
    {
	m_file->write(line, size);
    }
    if (level >= m_consoleOutputLevel)
    {
	if (level >= SLIM_DEBUG_WARNING_LEVEL)
	{
	    std::cerr << console::bold;
	}
	std::cerr << line << console::nothing;
    }
}

}
}
