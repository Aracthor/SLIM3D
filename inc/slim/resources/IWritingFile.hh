#ifndef SLIM_RESOURCES_IWRITING_FILE_HH_
# define SLIM_RESOURCES_IWRITING_FILE_HH_

namespace slim
{
namespace resources
{

class	IWritingFile
{
public:
    virtual ~IWritingFile() {}

public:
    virtual size_t	write(const void* data, size_t size) = 0;
};

}
}

#endif // !SLIM_RESOURCES_IWRITING_FILE_HH_
