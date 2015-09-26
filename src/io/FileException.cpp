#include "slim/io/FileException.hh"

#include <cstring>

namespace slim
{
namespace io
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
