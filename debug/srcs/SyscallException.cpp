//
// SyscallException.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 17:27:31 2015 Aracthor
// Last Update Thu Sep  3 23:03:41 2015 Aracthor
//

#include "slim3d/debug/SyscallException.hh"

#include <cerrno>
#include <cstring>

namespace slim
{
namespace debug
{

SyscallException::SyscallException(const char* message, const char* file, const char* function, int line) :
    Exception(message, file, function, line)
{
    size_t	currentSize = strlen(m_whatMessage);

    m_errno = errno;

    strncat(m_whatMessage, ": ", SLIM3D_DEBUG_MESSAGE_BUFFER_SIZE - currentSize);
    strncat(m_whatMessage, strerror(m_errno), SLIM3D_DEBUG_MESSAGE_BUFFER_SIZE - currentSize - 2);
}

SyscallException::~SyscallException() throw()
{
}

}
}
