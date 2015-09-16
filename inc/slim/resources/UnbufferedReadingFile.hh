#ifndef SLIM_RESOURCES_UNBUFFERED_READING_FILE_HH_
# define SLIM_RESOURCES_UNBUFFERED_READING_FILE_HH_

# include "slim/resources/UnbufferedFile.hh"
# include "slim/resources/IReadingFile.hh"

namespace slim
{
namespace resources
{

class	UnbufferedReadingFile : public UnbufferedFile,
				public IReadingFile
{
public:
    UnbufferedReadingFile(const char* name);
    virtual ~UnbufferedReadingFile() noexcept(false);

public:
    size_t	read(void* buffer, size_t size);
};

}
}

#endif // !SLIM_RESOURCES_UNBUFFERED_READING_FILE_HH_
