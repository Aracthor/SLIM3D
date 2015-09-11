//
// FileException.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 13:38:28 2015 Aracthor
// Last Update Wed Sep  9 23:58:26 2015 Aracthor
//

#ifndef SLIM3D_RESOURCES_FILE_EXCEPTION_HH_
# define SLIM3D_RESOURCES_FILE_EXCEPTION_HH_

# include "slim3d/debug/SyscallException.hh"

namespace slim
{
namespace resources
{

class	FileException : public debug::SyscallException
{
public:
    FileException(const char* fileName, const char* message,
		  const char* file, const char* function, int line);
    virtual ~FileException() throw();

public:
    inline const char*	getFileName() const;

protected:
    const char*	m_fileName;
};

}
}

# include "FileException.hpp"

#endif // !SLIM3D_RESOURCES_FILE_EXCEPTION_HH_
