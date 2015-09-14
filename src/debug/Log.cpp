#include "slim/core/system.h"
#include "slim/debug/Log.hh"
#include "slim/maths/lib.hh"

namespace slim
{
namespace debug
{

LogBase::LogBase(const char* name) :
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

LogBase::~LogBase()
{
}


void
LogBase::manageActivations()
{
    unsigned int	minimumLevel = maths::lib::min(m_fileOutputLevel, m_consoleOutputLevel);

    log.setActive(minimumLevel <= 0);
    info.setActive(minimumLevel <= 1);
    warning.setActive(minimumLevel <= 2);
    error.setActive(minimumLevel <= 3);
}

}
}

# if IS_COMPUTER(SLIM_CORE_SYSTEM)
#  include "Log/ConsoleLog.cpp"
# else
#  error "Log class not created for this system."
# endif
