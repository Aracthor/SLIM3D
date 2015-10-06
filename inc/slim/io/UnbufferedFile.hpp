#ifndef SLIM_IO_UNBUFFERED_FILE_HH_
# define SLIM_IO_UNBUFFERED_FILE_HH_

# include "slim/system.h"

namespace slim
{
namespace io
{

class	UnbufferedFile
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
    UnbufferedFile();
    virtual ~UnbufferedFile() noexcept(false);

protected:
    FileHandle	m_fd;
};

}
}

#endif // !SLIM_IO_UNBUFFERED_FILE_HH_
