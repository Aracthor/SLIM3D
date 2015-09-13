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
Log::flush(unsigned int level)
{
    if (level >= m_fileOutputLevel)
    {
	m_buffer[m_buffer.getSize()] = '\0';
	size_t size = snprintf(m_fileBuffer, SLIM_DEBUG_CONSOLE_LOG_BUFFER_SIZE,
			       "[%s] [%s] %s\n", m_name, s_levels[level], m_buffer.getData());
	m_file->write(m_fileBuffer, size);
    }
}

}
}
