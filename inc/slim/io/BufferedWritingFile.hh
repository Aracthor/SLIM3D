#ifndef SLIM_IO_BUFFERED_WRITING_FILE_HH_
# define SLIM_IO_BUFFERED_WRITING_FILE_HH_

# include "slim/io/BufferedFile.hh"
# include "slim/io/WritingFile.hh"

namespace slim
{
namespace io
{

class	BufferedWritingFile : public BufferedFile,
			      public WritingFile
{
public:
    BufferedWritingFile(const char* name);
    virtual ~BufferedWritingFile();

public:
    size_t	write(const void* data, size_t size) override;
};

}
}

#endif // !SLIM_IO_BUFFERED_WRITING_FILE_HH_
