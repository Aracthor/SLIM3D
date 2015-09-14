#ifndef SLIM_RESOURCES_IFORMAT_LOADER_HH_
# define SLIM_RESOURCES_IFORMAT_LOADER_HH_

# include "slim/resources/data.hh"
# include "slim/resources/VirtualFile.hh"

namespace slim
{
namespace resources
{

class	IFormatLoader
{
public:
    struct		ImageData
    {
	unsigned int	width;
	unsigned int	height;
	byte*		pixels;
    };

public:
    virtual ~IFormatLoader() {}

public:
    virtual bool	load(const char* name, VirtualFile* file, ImageData& data) = 0;
};

}
}

#endif // !SLIM_RESOURCES_IFORMAT_LOADER_HH_
