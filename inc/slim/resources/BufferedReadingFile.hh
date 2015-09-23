#ifndef SLIM_RESOURCES_BUFFERED_READING_FILE_HH_
# define SLIM_RESOURCES_BUFFERED_READING_FILE_HH_

# include "slim/resources/BufferedFile.hh"
# include "slim/resources/ReadingFile.hh"

namespace slim
{
namespace resources
{

class	BufferedReadingFile : public BufferedFile,
			      public ReadingFile
{
public:
    BufferedReadingFile(const char* name);
    virtual ~BufferedReadingFile() noexcept(false);

public:
    size_t	read(void* buffer, size_t size) override;
};

}
}

#endif // !SLIM_RESOURCES_BUFFERED_READING_FILE_HH_
