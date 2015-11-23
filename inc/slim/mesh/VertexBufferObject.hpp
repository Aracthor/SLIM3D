#ifndef SLIM_MESH_VERTEX_BUFFER_OBJECT_HPP_
# define SLIM_MESH_VERTEX_BUFFER_OBJECT_HPP_

# include "slim/graphics/IBindable.hpp"
# include "slim/mesh/data.hpp"

# include "slim/graphics/gl.h"

namespace slim
{
namespace mesh
{

class	VertexBufferObject : public graphics::IBindable
{
public:
    VertexBufferObject(void* verticesData);
    VertexBufferObject(Index* indices);
    ~VertexBufferObject();

public:
    inline void	bind() const override;
    inline void	unbind() const override;

private:
    GLuint	m_id;
    GLenum	m_type;
};

}
}

# include "VertexBufferObject.ipp"

#endif // !SLIM_MESH_VERTEX_BUFFER_OBJECT_HPP_
