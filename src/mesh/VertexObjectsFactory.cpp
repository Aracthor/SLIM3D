#include "slim/debug/assert.hpp"
#include "slim/mesh/VertexObjectsFactory.hpp"

#include "slim/string.h"

namespace slim
{
namespace mesh
{

VertexObjectsFactory::VertexObjectsFactory(memory::Chunk& memory) :
    m_memory(memory)
{
    this->reset();
}

VertexObjectsFactory::~VertexObjectsFactory()
{
}


void
VertexObjectsFactory::setIndices(const Index* indices, unsigned int indicesNumber)
{
    m_indices = indices;
    m_indicesNumber = indicesNumber;
}


void
VertexObjectsFactory::create(VertexArrayObject& dest)
{
    unsigned int	index = 0;
    bool		useColor = (m_colors != nullptr);
    bool		useTexture = (m_textureCoords != nullptr);
    bool		useNormal = (m_normals != nullptr);
    float*		data;

    SLIM_DEBUG_ASSERT(m_positions != nullptr);
    SLIM_DEBUG_ASSERT(m_size > 0);
    data = m_memory.alloc<float>(m_size *
				 (SLIM_MESH_POSITION_SIZE +
				  SLIM_MESH_COLOR_SIZE +
				  SLIM_MESH_TEXTURE_SIZE +
				  SLIM_MESH_NORMAL_SIZE));

    memcpy(&data[index], m_positions, sizeof(Position) * m_size);
    index += sizeof(Position) / sizeof(float) * m_size;

    if (useColor)
    {
	memcpy(&data[index], m_colors, sizeof(Color) * m_size);
	index += sizeof(Color) / sizeof(float) * m_size;
    }

    if (useTexture)
    {
	memcpy(&data[index], m_textureCoords, sizeof(TextureCoord) * m_size);
	index += sizeof(TextureCoord) / sizeof(float) * m_size;
    }

    if (useNormal)
    {
	memcpy(&data[index], m_normals, sizeof(Normal) * m_size);
	index += sizeof(Normal) / sizeof(float) * m_size;
    }

    if (m_indices)
    {
	dest.create(data, m_indices, useColor, useTexture, useNormal, m_size, m_indicesNumber);
    }
    else
    {
	dest.create(data, useColor, useTexture, useNormal, m_size);
    }

    m_memory.free(data);
    this->reset();
}


void
VertexObjectsFactory::reset()
{
    m_size = 0;
    m_positions = nullptr;
    m_colors = nullptr;
    m_textureCoords = nullptr;
    m_normals = nullptr;
    m_indices = nullptr;
    m_indicesNumber = 0;
}

}
}
