#ifndef SLIM_RESOURCES_UNBUFFERED_READING_FILE_HH_
# define SLIM_RESOURCES_UNBUFFERED_READING_FILE_HH_

# include "slim/resources/ReadingFile.hh"
# include "slim/resources/UnbufferedFile.hh"

namespace slim
{
namespace resources
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

#endif // !SLIM_RESOURCES_UNBUFFERED_READING_FILE_HH_
