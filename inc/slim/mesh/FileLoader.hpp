#ifndef SLIM_FILE_MESH_LOADER_HPP_
# define SLIM_FILE_MESH_LOADER_HPP_

# include "slim/io/VirtualFile.hpp"

# include "slim/mesh/data.hpp"

namespace slim
{
namespace mesh
{

class	FileLoader
{
public:
    struct		Data
    {
	Position*	positions;
	Color*		colors;
	Normal*		normals;
	Index*		indices;
	unsigned int	number;
    };

public:
    FileLoader(memory::Chunk& memory);
    virtual ~FileLoader();

public:
    virtual bool	readFile(io::VirtualFile& file, Data& dest) = 0;

protected:
    memory::Chunk&	m_memory;
};

}
}

#endif // !SLIM_FILE_MESH_LOADER_HPP_
