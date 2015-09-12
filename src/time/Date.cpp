//
// Date.cpp for SLIM in /home/aracthor/programs/projects/SLIM/time
// 
// Made by Aracthor
// 
// Started on  Thu Sep  3 22:22:56 2015 Aracthor
// Last Update Thu Sep  3 22:57:41 2015 Aracthor
//

#include "slim/debug/SyscallException.hh"
#include "slim/time/Date.hh"

namespace slim
{
namespace time
{

Date::Date(time_t seconds, bool local) :
    m_local(local)
{
    if (seconds == static_cast<time_t>(-1))
    {
	throw debug::SyscallException("Cannot get current time", __FILE__, __func__, __LINE__);
    }
    this->setSeconds(seconds);
}

Date::~Date()
{
}


void
Date::setSeconds(time_t seconds)
{
    m_seconds = seconds;
    if (m_local)
    {
	m_completeTime = localtime(&seconds);
    }
    else
    {
	m_completeTime = gmtime(&seconds);
    }
}

}
}
