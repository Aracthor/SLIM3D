#include "slim/graphics/glDebug.hpp"
#include "slim/mesh/data.hpp"
#include "slim/mesh/VertexArrayObject.hpp"

namespace slim
{
namespace mesh
{

VertexArrayObject::VertexArrayObject(const VertexBufferObject& vbo,
				     bool useColor, bool useTexture, bool useNormal, unsigned int size)
{
    this->createGLResource();

    this->bind();
    {
	this->bindData(vbo, useColor, useTexture, useNormal, size);
    }
    this->unbind();
}

VertexArrayObject::VertexArrayObject(const VertexBufferObject& dataVbo, const VertexBufferObject& indexVbo,
				     bool useColor, bool useTexture, bool useNormal, unsigned int size)
{
    this->createGLResource();

    this->bind();
    {
	this->bindData(dataVbo, useColor, useTexture, useNormal, size);
	indexVbo.bind();
    }
    this->unbind();
}

VertexArrayObject::~VertexArrayObject()
{
    glDeleteVertexArrays(1, &m_id);
}


void
VertexArrayObject::createGLResource()
{
    glGenVertexArrays(1, &m_id);
    SLIM_GRAPHICS_GL_CHECK();
}

void
VertexArrayObject::bindData(const VertexBufferObject& vbo,
			    bool useColor, bool useTexture, bool useNormal, unsigned int size)
{
    unsigned int	index = 0;

    vbo.bind();
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

    // vbo.unbind(); // TODO check if can be uncommented
}

}
}
