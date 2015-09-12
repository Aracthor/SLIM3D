//
// UnbufferedFile.cpp for SLIM in /home/aracthor/programs/projects/SLIM/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:25:04 2015 Aracthor
// Last Update Wed Sep  2 17:10:10 2015 Aracthor
//

#include "slim/resources/UnbufferedFile.hh"

namespace slim
{
namespace resources
{

UnbufferedFile::UnbufferedFile(const char* name) :
    File(name)
{
}

UnbufferedFile::~UnbufferedFile()
{
    SLIM_DEBUG_SYSCALL_CALL(close(m_fd));
}

}
}
