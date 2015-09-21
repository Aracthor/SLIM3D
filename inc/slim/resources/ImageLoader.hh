#ifndef SLIM_RESOURCES_IMAGE_LOADER_HH_
# define SLIM_RESOURCES_IMAGE_LOADER_HH_

# include "slim/resources/data.hh"

namespace slim
{
namespace resources
{

class			ImageLoader
{
public:
    struct		ImageData
    {
	unsigned int	width;
	unsigned int	height;
	byte*		pixels;
    };

public:
    ImageLoader();
    ~ImageLoader();

public:
    bool	loadImage(const char* fileName, ImageData& data);

private:
    void	giveErrorImage(ImageData& data) const;
};

}
}

#endif // !SLIM_RESOURCES_IMAGE_LOADER_HH_
