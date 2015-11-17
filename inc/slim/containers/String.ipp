#include "slim/string.h"

namespace slim
{
namespace containers
{

String::String(const char* data) :
    m_data(data)
{
}

String::String(const String& reference) :
    m_data(reference.getData())
{
}

String::~String()
{
}


const char*
String::getData() const
{
    return m_data;
}


char
String::operator[](unsigned int index) const
{
    return m_data[index];
}


bool
String::operator==(const char* string) const
{
    return !strcmp(m_data, string);
}

bool
String::operator!=(const char* string) const
{
    return strcmp(m_data, string);
}

bool
String::operator==(const String& string) const
{
    return !strcmp(m_data, string.getData());
}

bool
String::operator!=(const String& string) const
{
    return strcmp(m_data, string.getData());
}

bool
String::operator<(const String& string) const
{
    return (strcmp(m_data, string.getData()) < 0);
}

}
}
