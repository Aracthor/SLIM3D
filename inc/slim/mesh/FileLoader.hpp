#ifndef SLIM_MESH_FILE_LOADER_HPP_
# define SLIM_MESH_FILE_LOADER_HPP_

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
	Vertex*		vertices = nullptr;
	Index*		indices = nullptr;
	unsigned int	number = 0;
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

#endif // !SLIM_MESH_FILE_LOADER_HPP_
