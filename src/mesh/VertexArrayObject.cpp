#include "slim/graphics/glDebug.hpp"
#include "slim/mesh/data.hpp"
#include "slim/mesh/VertexArrayObject.hpp"

namespace slim
{
namespace mesh
{

VertexArrayObject::VertexArrayObject() :
    m_id(0)
{
}


void
VertexArrayObject::create(const void* data,
			  bool useColor, bool useTexture, bool useNormal, std::size_t size)
{
    m_useIndices = false;
    m_size = size;
    m_dataVbo.create(data, size);
    this->createGLResource();

    this->bind();
    {
	this->bindData(useColor, useTexture, useNormal, size);
    }
    this->unbind();
}

void
VertexArrayObject::create(const void* data, const Index* indices,
			  bool useColor, bool useTexture, bool useNormal, std::size_t size, std::size_t number)
{
    m_useIndices = true;
    m_size = size;
    m_dataVbo.create(data, size);
    m_indicesVbo.create(indices, number);
    this->createGLResource();

    this->bind();
    {
	this->bindData(useColor, useTexture, useNormal, size);
	m_indicesVbo.bind();
    }
    this->unbind();
}

VertexArrayObject::~VertexArrayObject()
{
    glDeleteVertexArrays(1, &m_id);
    SLIM_GRAPHICS_GL_CHECK();
}


void
VertexArrayObject::createGLResource()
{
    glGenVertexArrays(1, &m_id);
    SLIM_GRAPHICS_GL_CHECK();
}

void
VertexArrayObject::bindData(bool useColor, bool useTexture, bool useNormal, std::size_t size)
{
    unsigned int	index = 0;

    m_dataVbo.bind();
    glEnableVertexAttribArray(SLIM_MESH_POSITION_INDEX);
    glVertexAttribPointer(SLIM_MESH_POSITION_INDEX, SLIM_MESH_POSITION_SIZE, GL_FLOAT, GL_FALSE, 0,
			  reinterpret_cast<GLvoid*>(index));
    index += size * sizeof(Position);

    if (useColor)
    {
	glEnableVertexAttribArray(SLIM_MESH_COLOR_INDEX);
	glVertexAttribPointer(SLIM_MESH_COLOR_INDEX, SLIM_MESH_COLOR_SIZE, GL_FLOAT, GL_FALSE, 0,
			      reinterpret_cast<GLvoid*>(index));
	index += size * sizeof(Color);
    }

    if (useTexture)
    {
	glEnableVertexAttribArray(SLIM_MESH_TEXTURE_INDEX);
	glVertexAttribPointer(SLIM_MESH_TEXTURE_INDEX, SLIM_MESH_TEXTURE_SIZE, GL_FLOAT, GL_FALSE, 0,
			      reinterpret_cast<GLvoid*>(index));
	index += size * sizeof(TextureCoord);
    }

    if (useNormal)
    {
	glEnableVertexAttribArray(SLIM_MESH_NORMAL_INDEX);
	glVertexAttribPointer(SLIM_MESH_NORMAL_INDEX, SLIM_MESH_NORMAL_SIZE, GL_FLOAT, GL_FALSE, 0,
			      reinterpret_cast<GLvoid*>(index));
	index += size * sizeof(Normal);
    }

    m_dataVbo.unbind();
}

}
}
