#ifndef SLIM_ASSETS_IMAGE_HH_
# define SLIM_ASSETS_IMAGE_HH_

# include "slim/assets/Asset.hh"
# include "slim/assets/ImageLoader.hh"

# define SLIM_ASSETS_IMAGE_ASSET_TYPE	"image"

namespace slim
{
namespace assets
{

class	Image : public Asset
{
private:
    static ImageLoader	s_imageLoader;

public:
    static Image*	getErrorImage(); // Return single white pixel.
    static Image*	createFromFile(const char* fileName);

private:
    Image(const char* name, unsigned int width, unsigned int height, byte* pixels);
    explicit Image(const char* fileName);

public:
    Image(const Image& reference);
    virtual ~Image();

public:
    inline unsigned int	getWidth() const;
    inline unsigned int	getHeight() const;
    inline const byte*	getPixels() const;

protected:
    unsigned int	m_width;
    unsigned int	m_height;
    byte*		m_pixels;
};

}
}

# include "Image.hpp"

#endif // !SLIM_ASSETS_IMAGE_HH_
