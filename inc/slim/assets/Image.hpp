#ifndef SLIM_ASSETS_IMAGE_HPP_
# define SLIM_ASSETS_IMAGE_HPP_

# include "slim/data.hpp"
# include "slim/assets/Asset.hpp"
# include "slim/assets/SingleFileAsset.hpp"

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

# include "Image.ipp"

#endif // !SLIM_ASSETS_IMAGE_HPP_
