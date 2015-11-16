#ifndef SLIM_MESH_MATERIAL_HPP_
# define SLIM_MESH_MATERIAL_HPP_

# include "slim/shader/Program.hpp"

namespace slim
{
namespace mesh
{

class	Material
{
public:
    Material(shader::Program* shader);
    Material(const Material& material);
    ~Material();

public:
    inline const shader::Program*	getShader() const;

private:
    const shader::Program*	m_shader = nullptr;
};

}
}

# include "Material.ipp"

#endif // !SLIM_MESH_MATERIAL_HPP_
