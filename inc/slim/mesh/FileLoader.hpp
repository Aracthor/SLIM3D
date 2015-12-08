#ifndef SLIM_MESH_FILE_LOADER_HPP_
# define SLIM_MESH_FILE_LOADER_HPP_

# include "slim/io/VirtualFile.hpp"
# include "slim/mesh/data.hpp"
# include "slim/mesh/VertexObjectsFactory.hpp"

namespace slim
{
namespace mesh
{

class	FileLoader
{
public:
    struct		Data
    {
	Position*	positions = nullptr;
	Color*		colors = nullptr;
	TextureCoord*	textureCoords = nullptr;
	Normal*		normals = nullptr;
	Index*		indices = nullptr;
	unsigned int	number = 0;
	unsigned int	indicesNumber = 0;
    };

public:
    FileLoader(memory::Chunk& memory);
    virtual ~FileLoader();

public:
    virtual bool	readFile(io::VirtualFile& file, Data& dest) = 0;

protected:
    memory::Chunk&      m_memory;
};

}
}

#endif // !SLIM_MESH_FILE_LOADER_HPP_
