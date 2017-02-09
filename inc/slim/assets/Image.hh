#ifndef SLIM_ASSETS_IMAGE_HH_
# define SLIM_ASSETS_IMAGE_HH_

# include "slim/assets/Asset.hh"
# include "slim/assets/data.hh"
# include "slim/assets/SingleFileAsset.hh"

namespace slim
{
namespace assets
{

class			Image : public SingleFileAsset
{
public:
    static const char* const	typeName;

public:
    static Image*	getErrorImage(); // Return single white pixel.

public:
    explicit Image(const char* const name);
    Image(const Image& reference);
    virtual ~Image();

public:
    inline unsigned int	getWidth() const;
    inline unsigned int	getHeight() const;
    inline const byte*	getPixels() const;

protected:
    bool	loadFromFile(const char* const path) override;
    void	unloadData() override;

private:
    void	setErrorImage();
    void	setData(unsigned int width, unsigned int height, byte* pixels);

protected:
    unsigned int	m_width;
    unsigned int	m_height;
    byte*		m_pixels;
};

}
}

# include "Image.hpp"

#endif // !SLIM_ASSETS_IMAGE_HH_