#ifndef SLIM_RESOURCES_BUFFERED_WRITING_FILE_HH_
# define SLIM_RESOURCES_BUFFERED_WRITING_FILE_HH_

# include "slim/resources/BufferedFile.hh"
# include "slim/resources/WritingFile.hh"

namespace slim
{
namespace resources
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

#endif // !SLIM_RESOURCES_BUFFERED_WRITING_FILE_HH_
