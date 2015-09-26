#ifndef SLIM_ASSETS_IMAGE_LOADER_HH_
# define SLIM_ASSETS_IMAGE_LOADER_HH_

# include "slim/assets/data.hh"

namespace slim
{
namespace assets
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

#endif // !SLIM_ASSETS_IMAGE_LOADER_HH_
