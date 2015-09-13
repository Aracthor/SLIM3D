#ifndef SLIM_RESOURCES_IMAGE_HH_
# define SLIM_RESOURCES_IMAGE_HH_

# include "slim/resources/data.hh"

namespace slim
{
namespace resources
{

class	Image
{
public:
    explicit Image(const char* fileName);
    Image(const Image& reference);
    virtual ~Image();

public:
    inline const char*	getName() const;
    inline unsigned int	getWidth() const;
    inline unsigned int	getHeight() const;
    inline const byte*	getPixels() const;

protected:
    const char*		m_name;
    unsigned int	m_width;
    unsigned int	m_height;
    byte*		m_pixels;
};

}
}

# include "Image.hpp"

#endif // !SLIM_RESOURCES_IMAGE_HH_
