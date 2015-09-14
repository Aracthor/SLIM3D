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
    void	init();
    void	destroy();

private:
    const char*	getExtention(const char* fileName) const;
    void	giveErrorImage(ImageData& data) const;

private:
    unsigned int        m_counter = 0;
};

}
}

# include "ImageLoader.hpp"

#endif // !SLIM_RESOURCES_IMAGE_LOADER_HH_
