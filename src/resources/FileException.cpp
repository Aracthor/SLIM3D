#include "slim/resources/FileException.hh"

#include <cstring>

namespace slim
{
namespace resources
{

FileException::FileException(const char* fileName, const char* message,
			     const char* file, const char* function, int line) :
    SyscallException(message, file, function, line),
    m_fileName(fileName)
{
}

FileException::~FileException() throw()
{
}

}
}
