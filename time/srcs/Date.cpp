//
// Date.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/time
// 
// Made by Aracthor
// 
// Started on  Thu Sep  3 22:22:56 2015 Aracthor
// Last Update Thu Sep  3 22:40:31 2015 Aracthor
//

#include "slim3d/time/Date.hh"

namespace slim
{
namespace time
{

Date::Date(time_t seconds, bool local) :
    m_local(local)
{
    if (seconds == static_cast<time_t>(-1))
    {
	throw SyscallException("Cannot get current time", __FILE__, __func__, __LINE__);
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
