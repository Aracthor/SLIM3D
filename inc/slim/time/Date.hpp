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
