namespace slim
{
namespace mesh
{

const shader::Program*
Material::getShader() const
{
    return m_shader;
}

const texture::Texture*
Material::getTexture() const
{
    return m_texture;
}

}
}
