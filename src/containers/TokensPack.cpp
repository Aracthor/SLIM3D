#include "slim/containers/TokensPack.hpp"

#include "slim/string.h"

namespace slim
{
namespace containers
{

TokensPack::TokensPack(char* str, char separator) :
    m_data(str),
    m_lastSeparatorFound(str),
    m_separator(separator)
{
}

TokensPack::~TokensPack()
{
}


char*
TokensPack::getNextToken()
{
    if (m_lastSeparatorFound == nullptr)
    {
	return nullptr;
    }

    char*	ptr = strchr(m_lastSeparatorFound, m_separator);
    char*	token;

    if (ptr != nullptr)
    {
	*ptr = '\0';
	token = m_lastSeparatorFound;
	m_lastSeparatorFound = ptr + 1;
	while (*m_lastSeparatorFound == m_separator)
	{
	    m_lastSeparatorFound++;
	}
    }
    else
    {
	token = m_lastSeparatorFound;
	m_lastSeparatorFound = nullptr;
    }

    return token;

}

}
}
