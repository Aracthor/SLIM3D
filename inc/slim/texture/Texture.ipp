namespace slim
{
namespace texture
{

void
Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void
Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

}
}
