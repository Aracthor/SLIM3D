//
// File.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:17:30 2015 Aracthor
// Last Update Wed Sep  2 15:02:45 2015 Aracthor
//

#include "slim3d/resources/File.hh"

#include <cstdio>

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
    char	buffer[SLIM3D_DEBUG_EXCEPTION_BUFFER_SIZE];

    snprintf(buffer, SLIM3D_DEBUG_EXCEPTION_BUFFER_SIZE, "%s %s.", message, m_name);
    throw FileException(m_name, buffer, __FILE__, __func__, __LINE__);
}
