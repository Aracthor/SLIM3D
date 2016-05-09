#ifndef SLIM_MESH_MATERIAL_HPP_
# define SLIM_MESH_MATERIAL_HPP_

# include "slim/assets/Asset.hpp"
# include "slim/shader/Program.hpp"
# include "slim/texture/Texture.hpp"

namespace slim
{
namespace mesh
{

class	Material : public assets::Asset
{
public:
    static const char* const	typeName;

    
public:
    Material(const shader::Program* shader, const char* name);
    Material(const Material& material);
    ~Material();

public:
    void	setShader(const shader::Program* shader);
    void	setTexture(const texture::Texture* texture);

public:
    inline const shader::Program*	getShader() const;
    inline const texture::Texture*	getTexture() const;

private:
    const shader::Program*	m_shader = nullptr;
    const texture::Texture*	m_texture = nullptr;
};

}
}

# include "Material.ipp"

#endif // !SLIM_MESH_MATERIAL_HPP_
