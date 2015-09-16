#ifndef SLIM_RESOURCES_UNBUFFERED_FILE_HH_
# define SLIM_RESOURCES_UNBUFFERED_FILE_HH_

# include "slim/core/system.h"
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
# elif SLIM_CORE_SYSTEM_IS_WINDOWS
    typedef void*	FileHandle;
# else
#  error "UnbufferedFile not handled for this system."
# endif

public:
    UnbufferedFile(const char* name);
    virtual ~UnbufferedFile() noexcept(false);

protected:
    FileHandle	m_fd;
};

}
}

#endif // !SLIM_RESOURCES_UNBUFFERED_FILE_HH_
