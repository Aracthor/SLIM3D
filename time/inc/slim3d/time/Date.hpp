//
// Date.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/time
// 
// Made by Aracthor
// 
// Started on  Thu Sep  3 22:26:31 2015 Aracthor
// Last Update Thu Sep  3 22:42:14 2015 Aracthor
//

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
