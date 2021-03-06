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
    VertexArrayObject();
    ~VertexArrayObject();

public:
    void	create(const void* data,
		       bool useColor, bool useTexture, bool useNormal, std::size_t size);
    void	create(const void* data, const Index* indices,
		       bool useColor, bool useTexture, bool useNormal, std::size_t size, std::size_t number);

public:
    inline void	bind() const override;
    inline void	unbind() const override;

public:
    inline bool		useIndices() const;
    inline unsigned int	getSize() const;

private:
    void	createGLResource();
    void	bindData(bool useColor, bool useTexture, bool useNormal, std::size_t size);

private:
    GLuint		m_id;
    bool		m_useIndices;
    std::size_t		m_size;
    VertexBufferObject	m_dataVbo;
    VertexBufferObject	m_indicesVbo;
};

}
}

# include "VertexArrayObject.ipp"

#endif // !SLIM_MESH_VERTEX_ARRAY_OBJECT_HPP_
