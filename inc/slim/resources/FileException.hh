#ifndef SLIM_RESOURCES_FILE_EXCEPTION_HH_
# define SLIM_RESOURCES_FILE_EXCEPTION_HH_

# include "slim/debug/SyscallException.hh"

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

#endif // !SLIM_RESOURCES_FILE_EXCEPTION_HH_