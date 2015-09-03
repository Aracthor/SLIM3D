//
// ComputerLog.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Tue Sep  1 23:32:18 2015 Aracthor
// Last Update Thu Sep  3 23:23:35 2015 Aracthor
//

#include "slim3d/resources/BufferedWritingFile.hh"

#include <cstdio>

namespace slim
{
namespace debug
{

void
Log::init(resources::Directory& directory)
{
    char	fileName[SLIM3D_DEBUG_LOG_NAME_BUFFER_SIZE];

    strncpy(fileName, m_name, SLIM3D_DEBUG_LOG_NAME_BUFFER_SIZE);
    strncat(fileName, ".slim3d.log", SLIM3D_DEBUG_LOG_NAME_BUFFER_SIZE - strlen(m_name));
    m_file = directory.newFile<resources::BufferedWritingFile>(fileName);
}

void
Log::destroy()
{
    delete (m_file);
}


void
Log::write(const char* message, int level)
{
    if (m_fileOutputLevel >= level)
    {
	size_t size = snprintf(m_buffer, SLIM3D_DEBUG_CONSOLE_LOG_BUFFER_SIZE,
			       "[%s] [%s] %s\n", m_name, s_levels[level], message);
	m_file->write(m_buffer, size);
    }
}

}
}
