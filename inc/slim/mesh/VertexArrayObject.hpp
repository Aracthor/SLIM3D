#ifndef SLIM_MESH_VERTEX_ARRAY_OBJECT_HPP_
# define SLIM_MESH_VERTEX_ARRAY_OBJECT_HPP_

# include "slim/graphics/IBindable.hpp"
# include "slim/mesh/VertexBufferObject.hpp"

# include "slim/graphics/gl.h"

# define SLIM_MESH_POSITION_INDEX	0
# define SLIM_MESH_COLOR_INDEX		1
# define SLIM_MESH_TEXTURE_INDEX	2
# define SLIM_MESH_NORMAL_INDEX		3

# define SLIM_MESH_POSITION_SIZE	3
# define SLIM_MESH_COLOR_SIZE		4
# define SLIM_MESH_TEXTURE_SIZE		2
# define SLIM_MESH_NORMAL_SIZE		3

namespace slim
{
namespace mesh
{

class	VertexArrayObject : public graphics::IBindable
{
public:
    VertexArrayObject(const VertexBufferObject& vbo,
		      bool useColor, bool useTexture, bool useNormal, unsigned int size);
    VertexArrayObject(const VertexBufferObject& dataVbo, const VertexBufferObject& indexVbo,
		      bool useColor, bool useTexture, bool useNormal, unsigned int size);
    ~VertexArrayObject();

public:
    inline void	bind() const override;
    inline void	unbind() const override;

private:
    void	createGLResource();
    void	bindData(const VertexBufferObject& vbo,
			 bool useColor, bool useTexture, bool useNormal, unsigned int size);

private:
    GLuint	m_id;
};

}
}

# include "VertexArrayObject.ipp"

#endif // !SLIM_MESH_VERTEX_ARRAY_OBJECT_HPP_
