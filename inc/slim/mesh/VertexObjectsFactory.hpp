#ifndef SLIM_MESH_VERTEX_OBJECTS_FACTORY_HPP_
# define SLIM_MESH_VERTEX_OBJECTS_FACTORY_HPP_

# include "slim/memory/Chunk.hpp"
# include "slim/mesh/VertexArrayObject.hpp"

namespace slim
{
namespace mesh
{

class	VertexObjectsFactory
{
public:
    VertexObjectsFactory(memory::Chunk& memory);
    ~VertexObjectsFactory();

public:
    inline void		setSize(unsigned int size);
    inline void		setPositions(const Position* positions);
    inline void		setColors(const Color* colors);
    inline void		setTextureCoords(const TextureCoord* textureCoords);
    inline void		setNormals(const Normal* normals);
    inline void		setIndices(const Index* indices);

public:
    VertexArrayObject	create();

private:
    void		reset();

private:
    memory::Chunk&	m_memory;

    unsigned int	m_size;
    const Position*	m_positions;
    const Color*	m_colors;
    const TextureCoord*	m_textureCoords;
    const Normal*	m_normals;
    const Index*	m_indices;
};

}
}

# include "VertexObjectsFactory.ipp"

#endif // !SLIM_MESH_VERTEX_OBJECTS_FACTORY_HPP_
