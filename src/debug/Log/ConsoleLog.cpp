//
// ComputerLog.cpp for SLIM in /home/aracthor/programs/projects/SLIM/debug
// 
// Made by Aracthor
// 
// Started on  Tue Sep  1 23:32:18 2015 Aracthor
// Last Update Wed Sep  9 13:47:53 2015 Aracthor
//

#include "slim/resources/BufferedWritingFile.hh"

#include <cstdio>

namespace slim
{
namespace debug
{

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
Log::write(const char* message, unsigned int level)
{
    if (m_fileOutputLevel >= level)
    {
	size_t size = snprintf(m_buffer, SLIM_DEBUG_CONSOLE_LOG_BUFFER_SIZE,
			       "[%s] [%s] %s\n", m_name, s_levels[level], message);
	m_file->write(m_buffer, size);
    }
}

}
}
