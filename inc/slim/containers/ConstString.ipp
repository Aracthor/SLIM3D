#include "slim/string.h"

namespace slim
{
namespace containers
{

const char*
ConstString::getData() const
{
    return m_data;
}


char
ConstString::operator[](unsigned int index) const
{
    return m_data[index];
}


bool
ConstString::operator==(const char* string) const
{
    return !strcmp(m_data, string);
}

bool
ConstString::operator!=(const char* string) const
{
    return strcmp(m_data, string);
}

bool
ConstString::operator==(const ConstString& string) const
{
    return !strcmp(m_data, string.getData());
}

bool
ConstString::operator!=(const ConstString& string) const
{
    return strcmp(m_data, string.getData());
}

bool
ConstString::operator<(const ConstString& string) const
{
    return (strcmp(m_data, string.getData()) < 0);
}

}
}
