#ifndef SLIM_MESH_MATERIAL_HPP_
# define SLIM_MESH_MATERIAL_HPP_

# include "slim/assets/Asset.hpp"
# include "slim/shader/Program.hpp"

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

public:
    inline const shader::Program*	getShader() const;

private:
    const shader::Program*	m_shader = nullptr;
};

}
}

# include "Material.ipp"

#endif // !SLIM_MESH_MATERIAL_HPP_
