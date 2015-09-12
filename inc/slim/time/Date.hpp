//
// Date.hpp for SLIM in /home/aracthor/programs/projects/SLIM/time
// 
// Made by Aracthor
// 
// Started on  Thu Sep  3 22:26:31 2015 Aracthor
// Last Update Wed Sep  9 10:41:12 2015 Aracthor
//

namespace slim
{
namespace time
{

bool
Date::isLocal() const
{
    return (m_local);
}

time_t
Date::getUnixSeconds() const
{
    return (m_seconds);
}

void
Date::toFormat(char* buffer, size_t size, const char* format) const
{
    strftime(buffer, size, format, m_completeTime);
}

}
}
