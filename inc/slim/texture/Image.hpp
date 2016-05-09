#ifndef SLIM_TEXTURE_IMAGE_HPP_
# define SLIM_TEXTURE_IMAGE_HPP_

# include "slim/data.hpp"
# include "slim/assets/SingleFileAsset.hpp"
# include "slim/memory/Chunk.hpp"

namespace slim
{
namespace texture
{

class			Image : public assets::SingleFileAsset
{
public:
    static const char* const	typeName;

public:
    Image(memory::Chunk& memory, const char* const name);
    virtual ~Image();

public:
    inline unsigned int	getWidth() const;
    inline unsigned int	getHeight() const;
    inline const byte*	getPixels() const;

protected:
    virtual bool	loadFromFile(const char* const path) override;
    virtual void	unloadData() override;

private:
    void	setErrorImage();
    void	setData(unsigned int width, unsigned int height, byte* pixels);

protected:
    memory::Chunk&	m_memory;
    unsigned int	m_width;
    unsigned int	m_height;
    byte*		m_pixels;
};

}
}

# include "Image.ipp"

#endif // !SLIM_TEXTURE_IMAGE_HPP_
