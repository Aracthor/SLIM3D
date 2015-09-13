#ifndef SLIM_RESOURCES_IFORMAT_LOADER_HH_
# define SLIM_RESOURCES_IFORMAT_LOADER_HH_

# include "slim/resources/data.hh"

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
    virtual void	load(const byte* fileData, ImageData& data) = 0;
};

}
}

#endif // !SLIM_RESOURCES_IFORMAT_LOADER_HH_
