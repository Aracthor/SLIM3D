#include "slim/graphics/glDebug.hpp"
#include "slim/mesh/VertexBufferObject.hpp"

namespace slim
{
namespace mesh
{

VertexBufferObject::~VertexBufferObject()
{
    glDeleteBuffers(1, &m_id);
}


VertexBufferObject::VertexBufferObject(void* verticesData) :
    m_type(GL_ARRAY_BUFFER)
{
    glGenBuffers(1, &m_id);
    SLIM_GRAPHICS_GL_CHECK();
    this->bind();
    {
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex), verticesData, GL_STATIC_DRAW);
	SLIM_GRAPHICS_GL_CHECK();
    }
    this->unbind();
}

VertexBufferObject::VertexBufferObject(Index* indices) :
    m_type(GL_ELEMENT_ARRAY_BUFFER)
{
    glGenBuffers(1, &m_id);
    SLIM_GRAPHICS_GL_CHECK();
    this->bind();
    {
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Index), indices, GL_STATIC_DRAW);
	SLIM_GRAPHICS_GL_CHECK();
    }
    this->unbind();
}


}
}
