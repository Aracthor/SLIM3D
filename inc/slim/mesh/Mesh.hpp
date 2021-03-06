#ifndef SLIM_MESH_MESH_HPP_
# define SLIM_MESH_MESH_HPP_

# include "slim/assets/SingleFileAsset.hpp"
# include "slim/memory/Chunk.hpp"
# include "slim/mesh/Loader.hpp"
# include "slim/mesh/Material.hpp"

# define SLIM_MESH_FILE_LINE_BUFFER_SIZE	0x1000

namespace slim
{
namespace mesh
{

class		Mesh : public assets::SingleFileAsset
{
public:
    enum	ERenderMode
    {
	points = 0,
	lines = 1,
	linesStrip = 2,
	linesFan = 3,
	triangles = 4,
	trianglesStrip = 5,
	trianglesFan = 6
    };

public:
    static const char* const	typeName;

public:
    static void			initLoader(memory::Chunk& memory);
    static void			destroyLoader(memory::Chunk& memory);

private:
    static Loader*		s_loader;


public:
    Mesh(const char* name);
    virtual ~Mesh();

public:
    void	draw() const;

public:
    inline ERenderMode		getRendermode() const;
    inline const Material*	getMaterial() const;

public:
    void        setMaterial(const Material* material);

protected:
    bool	loadFromFile(const char* const path) override;
    void	unloadData() override;

protected:
    ERenderMode		m_renderMode;
    const Material*	m_material;
    VertexArrayObject	m_vao;
};

}
}

# include "Mesh.ipp"

#endif // !SLIM_MESH_MESH_HPP_
