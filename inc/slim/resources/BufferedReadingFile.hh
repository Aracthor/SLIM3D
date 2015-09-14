#ifndef SLIM_RESOURCES_BUFFERED_READING_FILE_HH_
# define SLIM_RESOURCES_BUFFERED_READING_FILE_HH_

# include "slim/resources/BufferedFile.hh"
# include "slim/resources/IReadingFile.hh"

namespace slim
{
namespace resources
{

class	BufferedReadingFile : public BufferedFile,
			      public IReadingFile
{
public:
    BufferedReadingFile(const char* name);
    virtual ~BufferedReadingFile();

public:
    size_t	read(void* buffer, size_t size);
};

}
}

#endif // !SLIM_RESOURCES_BUFFERED_READING_FILE_HH_
