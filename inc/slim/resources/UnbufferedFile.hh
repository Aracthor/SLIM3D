#ifndef SLIM_RESOURCES_UNBUFFERED_FILE_HH_
# define SLIM_RESOURCES_UNBUFFERED_FILE_HH_

# include "slim/resources/File.hh"

namespace slim
{
namespace resources
{

class	UnbufferedFile : public File
{
protected:
# if SLIM_CORE_SYSTEM_IS_UNIX
    typedef int		FileHandle;
# else
    typedef void*	FileHandle;
# endif

public:
    UnbufferedFile(const char* name);
    virtual ~UnbufferedFile();

protected:
    FileHandle	m_fd;
};

}
}

#endif // !SLIM_RESOURCES_UNBUFFERED_FILE_HH_
