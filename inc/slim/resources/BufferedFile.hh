#ifndef SLIM_RESOURCES_BUFFERED_FILE_HH_
# define SLIM_RESOURCES_BUFFERED_FILE_HH_

# include "slim/resources/File.hh"

# include <cstdio>

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
