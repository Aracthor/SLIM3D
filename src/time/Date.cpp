#include "slim/string.h"
#include "slim/debug/exit.hpp"
#include "slim/time/Date.hpp"

#include <cerrno>

// Disable warnings for localtime and gmtime use from Visual Studio
# ifdef _MSC_VER
#  pragma warning(disable: 4996)
# endif // _MSC_VER

namespace slim
{
namespace time
{

Date::Date(time_t seconds, bool local) :
    m_local(local)
{
    if (seconds == static_cast<time_t>(-1))
    {
	SLIM_DEBUG_EXIT("Cannot get current time: ", strerror(errno));
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
