//
// Log.cpp for SLIM in /home/aracthor/programs/projects/SLIM/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:13:05 2015 Aracthor
// Last Update Sun Sep  6 23:28:25 2015 Aracthor
//

#include "slim/core/system.h"
#include "slim/debug/Log.hh"

namespace slim
{
namespace debug
{

const char*
LogBase::s_levels[4] = {"LOG", "INFO", "WARNING", "ERROR"};


LogBase::LogBase(const char* name) :
    m_name(name)
{
#ifdef _DEBUG
    m_fileOutputLevel = 0;
    m_consoleOutputLevel = 1;
#else
    m_fileOutputLevel = 1;
    m_consoleOutputLevel = 2;
#endif
}

LogBase::~LogBase()
{
}


Log::Log(const char* name) :
    LogBase(name)
{
}

Log::~Log()
{
}

}
}

# if IS_COMPUTER(SLIM_CORE_SYSTEM)
#  include "Log/ConsoleLog.cpp"
# else
#  error "Log class not created for this system."
# endif
