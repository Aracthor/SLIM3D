#ifndef SLIM_TEXTURE_TEXTURE_HPP_
# define SLIM_TEXTURE_TEXTURE_HPP_

# include "slim/graphics/gl.h"
# include "slim/texture/Image.hpp"

namespace slim
{
namespace texture
{

class	Texture : public Image
{
public:
    Texture(memory::Chunk& memory, const char* const name);
    ~Texture();

public:
    inline void	bind() const;
    inline void	unbind() const;

protected:
    bool	loadFromFile(const char* const path) override;
    void	unloadData() override;

private:
    GLuint	m_id;
};

}
}

# include "Texture.ipp"

#endif // !SLIM_TEXTURE_TEXTURE_HPP_
