#ifndef SLIM_RESOURCES_WRITING_FILE_HH_
# define SLIM_RESOURCES_WRITING_FILE_HH_

# include "slim/resources/File.hh"

namespace slim
{
namespace resources
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

#endif // !SLIM_RESOURCES_WRITING_FILE_HH_
