#ifndef SLIM_IO_UNBUFFERED_WRITING_FILE_HH_
# define SLIM_IO_UNBUFFERED_WRITING_FILE_HH_

# include "slim/io/UnbufferedFile.hh"
# include "slim/io/WritingFile.hh"

namespace slim
{
namespace io
{

class	UnbufferedWritingFile : public UnbufferedFile,
				public WritingFile
{
public:
    UnbufferedWritingFile(const char* name);
    virtual ~UnbufferedWritingFile() noexcept(false);

public:
    size_t	write(const void* data, size_t size) override;
};

}
}

#endif // !SLIM_IO_UNBUFFERED_WRITING_FILE_HH_
