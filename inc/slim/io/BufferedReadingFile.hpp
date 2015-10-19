#ifndef SLIM_IO_BUFFERED_READING_FILE_HH_
# define SLIM_IO_BUFFERED_READING_FILE_HH_

# include "slim/io/BufferedFile.hpp"
# include "slim/io/ReadingFile.hpp"

namespace slim
{
namespace io
{

class	BufferedReadingFile : public BufferedFile,
			      public ReadingFile
{
public:
    BufferedReadingFile(const char* name);
    virtual ~BufferedReadingFile();

public:
    size_t	read(void* buffer, size_t size) override;
};

}
}

#endif // !SLIM_IO_BUFFERED_READING_FILE_HH_
