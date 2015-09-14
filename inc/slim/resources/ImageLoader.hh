#ifndef SLIM_RESOURCES_IMAGE_LOADER_HH_
# define SLIM_RESOURCES_IMAGE_LOADER_HH_

# include "slim/resources/data.hh"
# include "slim/resources/IFormatLoader.hh"

namespace slim
{
namespace resources
{

class			ImageLoader
{
public:
    ImageLoader();
    ~ImageLoader();

public:
    void	preventImageCreation();
    bool	loadImage(const char* fileName, IFormatLoader::ImageData& data);
    void	preventImageDeletion();

private:
    void	init();
    void	destroy();

private:
    const char*	getExtention(const char* fileName) const;
    void	giveErrorImage(IFormatLoader::ImageData& data) const;

private:
    unsigned int        m_counter = 0;
    IFormatLoader*	m_bmpLoader;
};

}
}

# include "ImageLoader.hpp"

#endif // !SLIM_RESOURCES_IMAGE_LOADER_HH_
