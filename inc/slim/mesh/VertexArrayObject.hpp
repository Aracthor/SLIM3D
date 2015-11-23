#ifndef SLIM_MESH_VERTEX_ARRAY_OBJECT_HPP_
# define SLIM_MESH_VERTEX_ARRAY_OBJECT_HPP_

# include "slim/graphics/IBindable.hpp"

# include "slim/graphics/gl.h"

namespace slim
{
namespace mesh
{

class	VertexArrayObject : public graphics::IBindable
{
public:
    ~VertexArrayObject();

public:
    inline void	bind() const override;
    inline void	unbind() const override;

private:
    GLuint	m_id;
};

}
}

# include "VertexArrayObject.ipp"

#endif // !SLIM_MESH_VERTEX_ARRAY_OBJECT_HPP_
