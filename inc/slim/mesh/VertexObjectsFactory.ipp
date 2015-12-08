namespace slim
{
namespace mesh
{

void
VertexObjectsFactory::setSize(unsigned int size)
{
    m_size = size;
}

void
VertexObjectsFactory::setPositions(const Position* positions)
{
    m_positions = positions;
}

void
VertexObjectsFactory::setColors(const Color* colors)
{
    m_colors = colors;
}

void
VertexObjectsFactory::setTextureCoords(const TextureCoord* textureCoords)
{
    m_textureCoords = textureCoords;
}

void
VertexObjectsFactory::setNormals(const Normal* normals)
{
    m_normals = normals;
}

}
}
