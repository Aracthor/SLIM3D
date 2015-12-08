#include "slim/graphics/glDebug.hpp"
#include "slim/mesh/VertexBufferObject.hpp"

namespace slim
{
namespace mesh
{

VertexBufferObject::VertexBufferObject() :
    m_id(0)
{
}

VertexBufferObject::~VertexBufferObject()
{
    if (m_id != 0)
    {
	glDeleteBuffers(1, &m_id);
    }
}


void
VertexBufferObject::create(const void* verticesData, std::size_t size)
{
    m_type = GL_ARRAY_BUFFER;
    glGenBuffers(1, &m_id);
    SLIM_GRAPHICS_GL_CHECK();
    this->bind();
    {
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * size, verticesData, GL_STATIC_DRAW);
	SLIM_GRAPHICS_GL_CHECK();
    }
    this->unbind();
}

void
VertexBufferObject::create(const Index* indices, std::size_t size)
{
    m_type = GL_ELEMENT_ARRAY_BUFFER;
    glGenBuffers(1, &m_id);
    SLIM_GRAPHICS_GL_CHECK();
    this->bind();
    {
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Index) * size, indices, GL_STATIC_DRAW);
	SLIM_GRAPHICS_GL_CHECK();
    }
    this->unbind();
}


}
}
