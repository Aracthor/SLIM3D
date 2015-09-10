//
// SyscallException.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 17:26:27 2015 Aracthor
// Last Update Thu Sep 10 00:01:16 2015 Aracthor
//

namespace slim
{
namespace debug
{

int
SyscallException::getErrnoCode() const
{
    return (m_errno);
}

}
}
