#ifndef SLIM_MESH_MESH_HPP_
# define SLIM_MESH_MESH_HPP_

# include "slim/assets/SingleFileAsset.hpp"
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
    Mesh(const char* name);
    virtual ~Mesh();

protected:
    bool	loadFromFile(const char* const path) override;
    void	unloadData() override;

public:
    inline ERenderMode		getRendermode() const;
    inline const Material*	getMaterial() const;

protected:
    ERenderMode		m_renderMode;
    const Material*	m_material;
};

}
}

# include "Mesh.ipp"

#endif // !SLIM_MESH_MESH_HPP_
