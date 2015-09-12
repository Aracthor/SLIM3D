//
// File.cpp for SLIM in /home/aracthor/programs/projects/SLIM/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:17:30 2015 Aracthor
// Last Update Thu Sep  3 20:39:25 2015 Aracthor
//

#include "slim/resources/File.hh"

#include <cstdio>

namespace slim
{
namespace resources
{

File::File(const char* name) :
    m_name(name)
{
}

File::~File()
{
}


void
File::onError(const char* message) const
{
    char	buffer[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

    snprintf(buffer, SLIM_DEBUG_MESSAGE_BUFFER_SIZE, "%s %s.", message, m_name);
    throw FileException(m_name, buffer, __FILE__, __func__, __LINE__);
}

}
}
