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
