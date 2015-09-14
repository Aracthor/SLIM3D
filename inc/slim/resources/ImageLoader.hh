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
    void	preventImageCreation();
    bool	loadImage(const char* fileName, ImageData& data);
    void	preventImageDeletion();

private:
    void	giveErrorImage(ImageData& data) const;
};

}
}

# include "ImageLoader.hpp"

#endif // !SLIM_RESOURCES_IMAGE_LOADER_HH_
