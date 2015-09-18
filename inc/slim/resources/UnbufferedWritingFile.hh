#ifndef SLIM_RESOURCES_UNBUFFERED_WRITING_FILE_HH_
# define SLIM_RESOURCES_UNBUFFERED_WRITING_FILE_HH_

# include "slim/resources/UnbufferedFile.hh"
# include "slim/resources/IWritingFile.hh"

namespace slim
{
namespace resources
{

class	UnbufferedWritingFile : public UnbufferedFile,
				public IWritingFile
{
public:
    UnbufferedWritingFile(const char* name);
    virtual ~UnbufferedWritingFile() noexcept(false);

public:
    size_t	write(const void* data, size_t size);
};

}
}

#endif // !SLIM_RESOURCES_UNBUFFERED_WRITING_FILE_HH_
