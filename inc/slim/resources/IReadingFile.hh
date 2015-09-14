#ifndef SLIM_RESOURCES_IREADING_FILE_HH_
# define SLIM_RESOURCES_IREADING_FILE_HH_

namespace slim
{
namespace resources
{

class	IReadingFile
{
public:
    virtual ~IReadingFile() {}

public:
    virtual size_t	read(void* buffer, size_t size) = 0;
};

}
}

#endif // !SLIM_RESOURCES_IREADING_FILE_HH_
