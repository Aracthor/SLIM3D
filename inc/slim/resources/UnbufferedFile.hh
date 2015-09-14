#ifndef SLIM_RESOURCES_UNBUFFERED_FILE_HH_
# define SLIM_RESOURCES_UNBUFFERED_FILE_HH_

# include "slim/resources/File.hh"

# include <unistd.h>

namespace slim
{
namespace resources
{

class	UnbufferedFile : public File
{
public:
    UnbufferedFile(const char* name);
    virtual ~UnbufferedFile();

protected:
    int	m_fd;
};

}
}

#endif // !SLIM_RESOURCES_UNBUFFERED_FILE_HH_
