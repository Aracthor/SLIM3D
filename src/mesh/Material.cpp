#include "slim/debug/assert.hpp"
#include "slim/mesh/Material.hpp"

namespace slim
{
namespace mesh
{

const char* const
Material::typeName = "material";


Material::Material(const shader::Program* shader, const char* name) :
    assets::Asset(Material::typeName, name)
{
    SLIM_DEBUG_ASSERT(shader != nullptr);
    this->setShader(shader);
}

Material::Material(const Material& reference) :
    assets::Asset(Material::typeName, reference.getName())
{
    this->setShader(reference.getShader());
}

Material::~Material()
{
}


void
Material::setShader(const shader::Program* shader)
{
    m_shader = shader;
    this->listen(shader);
}

}
}
