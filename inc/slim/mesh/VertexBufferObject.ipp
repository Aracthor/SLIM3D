namespace slim
{
namespace mesh
{

void
VertexBufferObject::bind() const
{
    glBindBuffer(m_type, m_id);
}

void
VertexBufferObject::unbind() const
{
    glBindBuffer(m_type, 0);
}

}
}
