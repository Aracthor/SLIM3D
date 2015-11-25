#include "slim/debug/assert.hpp"
#include "slim/mesh/Material.hpp"

namespace slim
{
namespace mesh
{

Material::Material(shader::Program* shader) :
    m_shader(shader)
{
    SLIM_DEBUG_ASSERT(shader != nullptr);
}

Material::Material(const Material& reference) :
    m_shader(reference.getShader())
{
}

Material::~Material()
{
}

}
}
