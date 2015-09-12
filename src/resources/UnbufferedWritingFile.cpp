//
// UnbufferedWritingFile.cpp for SLIM in /home/aracthor/programs/projects/SLIM/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:50:16 2015 Aracthor
// Last Update Thu Sep  3 22:56:53 2015 Aracthor
//

#include "slim/resources/UnbufferedWritingFile.hh"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

namespace slim
{
namespace resources
{

UnbufferedWritingFile::UnbufferedWritingFile(const char* name) :
    UnbufferedFile(name)
{
    m_fd = open(name, O_RDONLY);
    if (m_fd == -1)
    {
	this->onError("Unbuffered mode, cannot open file");
    }
}

UnbufferedWritingFile::~UnbufferedWritingFile()
{
}


size_t
UnbufferedWritingFile::write(const void* data, size_t size)
{
    ssize_t	wrote = ::write(m_fd, data, size);

    if (wrote == -1)
    {
	this->onError("Unbuffered mode, error writing in");
    }

    return (wrote);
}

}
}
