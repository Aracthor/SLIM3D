namespace slim
{
namespace mesh
{

Mesh::ERenderMode
Mesh::getRendermode() const
{
    return m_renderMode;
}

const Material*
Mesh::getMaterial() const
{
    return m_material;
}


void
Mesh::setMaterial(const Material* material)
{
    m_material = material;
}

}
}
