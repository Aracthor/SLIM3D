//
// UnbufferedFile.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:25:04 2015 Aracthor
// Last Update Wed Sep  2 17:10:10 2015 Aracthor
//

#include "slim3d/resources/UnbufferedFile.hh"

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
    SLIM3D_DEBUG_SYSCALL_CALL(close(m_fd));
}

}
}
