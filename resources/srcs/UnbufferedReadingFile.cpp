//
// UnbufferedReadingFile.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:50:16 2015 Aracthor
// Last Update Thu Sep  3 22:56:31 2015 Aracthor
//

#include "slim3d/resources/UnbufferedReadingFile.hh"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

namespace slim
{
namespace resources
{

UnbufferedReadingFile::UnbufferedReadingFile(const char* name) :
    UnbufferedFile(name)
{
    m_fd = open(name, O_RDONLY);
    if (m_fd == -1)
    {
	this->onError("Unbuffered mode, cannot open file");
    }
}

UnbufferedReadingFile::~UnbufferedReadingFile()
{
}


size_t
UnbufferedReadingFile::read(void* buffer, size_t size)
{
    ssize_t extracted = ::read(m_fd, buffer, size);

    if (extracted == -1)
    {
	this->onError("Unbuffered mode, error reading from");
    }

    return (extracted);
}

}
}
