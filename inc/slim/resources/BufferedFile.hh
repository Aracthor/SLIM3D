#ifndef SLIM_RESOURCES_BUFFERED_FILE_HH_
# define SLIM_RESOURCES_BUFFERED_FILE_HH_

# include "slim/core/stdio.h"
    # include "slim/resources/File.hh"

namespace slim
{
namespace resources
{

class	BufferedFile : public File
{
public:
    BufferedFile(const char* name);
    virtual ~BufferedFile();

protected:
    FILE*	m_stream;
};

}
}

#endif // !SLIM_RESOURCES_BUFFERED_FILE_HH_
