//
// SyscallException.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 17:26:27 2015 Aracthor
// Last Update Wed Sep  2 17:26:42 2015 Aracthor
//

int
SyscallException::getErrnoCode() const
{
    return (m_errno);
}
