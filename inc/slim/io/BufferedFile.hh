#ifndef SLIM_IO_BUFFERED_FILE_HH_
# define SLIM_IO_BUFFERED_FILE_HH_

# include "slim/core/stdio.h"

namespace slim
{
namespace io
{

class	BufferedFile
{
public:
    BufferedFile();
    virtual ~BufferedFile() noexcept(false);

protected:
    FILE*	m_stream;
};

}
}

#endif // !SLIM_IO_BUFFERED_FILE_HH_
