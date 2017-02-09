#ifndef SLIM_IO_WRITING_FILE_HH_
# define SLIM_IO_WRITING_FILE_HH_

# include "slim/io/File.hh"

namespace slim
{
namespace io
{

class	WritingFile : public File
{
public:
    WritingFile(const char* name);
    virtual ~WritingFile() noexcept(false);

public:
    virtual size_t	write(const void* data, size_t size) = 0;
};

}
}

#endif // !SLIM_IO_WRITING_FILE_HH_