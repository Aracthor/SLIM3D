namespace slim
{
namespace mesh
{

void
VertexArrayObject::bind() const
{
    glBindVertexArray(m_id);
}

void
VertexArrayObject::unbind() const
{
    glBindVertexArray(0);
}

}
}
