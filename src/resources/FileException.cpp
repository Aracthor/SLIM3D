//
// FileException.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:03:53 2015 Aracthor
// Last Update Thu Sep  3 23:27:02 2015 Aracthor
//

#include "slim3d/resources/FileException.hh"

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
