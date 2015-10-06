#ifndef SLIM_IO_UNBUFFERED_READING_FILE_HH_
# define SLIM_IO_UNBUFFERED_READING_FILE_HH_

# include "slim/io/ReadingFile.hpp"
# include "slim/io/UnbufferedFile.hpp"

namespace slim
{
namespace io
{

class	UnbufferedReadingFile : public UnbufferedFile,
				public ReadingFile
{
public:
    UnbufferedReadingFile(const char* name);
    virtual ~UnbufferedReadingFile() noexcept(false);

public:
    size_t	read(void* buffer, size_t size) override;
};

}
}

#endif // !SLIM_IO_UNBUFFERED_READING_FILE_HH_
