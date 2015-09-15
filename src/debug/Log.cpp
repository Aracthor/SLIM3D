#include <iostream>

#include "slim/core/system.h"
#include "slim/debug/console.hh"
#include "slim/debug/Log.hh"
#include "slim/resources/BufferedWritingFile.hh"
#include "slim/maths/lib.hh"

namespace slim
{
namespace debug
{

Log::Log(const char* name) :
    log(this, name, 0),
    info(this, name, 1),
    warning(this, name, 2),
    error(this, name, 3),
    m_name(name)
{
#ifdef _DEBUG
    m_fileOutputLevel = 0;
    m_consoleOutputLevel = 1;
#else
    m_fileOutputLevel = 1;
    m_consoleOutputLevel = 2;
#endif

    this->manageActivations();
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


void
Log::manageActivations()
{
    unsigned int	minimumLevel = maths::lib::min(m_fileOutputLevel, m_consoleOutputLevel);

    log.setActive(minimumLevel <= 0);
    info.setActive(minimumLevel <= 1);
    warning.setActive(minimumLevel <= 2);
    error.setActive(minimumLevel <= 3);
}

}
}
