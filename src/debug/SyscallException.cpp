#include "slim/debug/SyscallException.hh"

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

    strncat(m_whatMessage, ": ", SLIM_DEBUG_MESSAGE_BUFFER_SIZE - currentSize);
    strncat(m_whatMessage, strerror(m_errno), SLIM_DEBUG_MESSAGE_BUFFER_SIZE - currentSize - 2);
}

SyscallException::~SyscallException() throw()
{
}

}
}
