//
// Log.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:13:05 2015 Aracthor
// Last Update Wed Sep  2 00:22:56 2015 Aracthor
//

#include "slim3d/core/system.h"
#include "slim3d/debug/Log.hh"

namespace slim
{
namespace debug
{

LogBase::LogBase(const char* name) :
    m_name(name)
{
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

# if IS_COMPUTER(SLIM3D_CORE_SYSTEM)
#  include "Log/ConsoleLog.cpp"
# else
#  error "Log class not created for this system."
# endif

}
}
