#ifndef SLIM_MESH_LOADER_HPP_
# define SLIM_MESH_LOADER_HPP_

# include <map> // TODO create our own

# include "slim/containers/ConstString.hpp"
# include "slim/memory/ArenaChunk.hpp"
# include "slim/mesh/FileLoader.hpp"

# include "slim/memory/units.h"

# define SLIM_MESH_LOADER_MEMORY	(20 * SLIM_MEMORY_MEBIBYTE)

namespace slim
{
namespace mesh
{

class	Loader
{
private:
    typedef memory::ArenaChunk	ChunkType;


public:
    Loader();
    ~Loader();

public:
    bool	loadFile(io::VirtualFile& file, FileLoader::Data& dest);
    void	deleteData(FileLoader::Data& data);

public:
    VertexArrayObject	generateVAO(const FileLoader::Data& data);

private:
    std::map<containers::ConstString, FileLoader*>	m_loaders;
    memory::Chunk&		m_memory;
    memory::Chunk::Checkpoint	m_checkpoint;
    VertexObjectsFactory	m_vertexObjectsFactory;
};

}
}

# include "Loader.ipp"

#endif // !SLIM_MESH_LOADER_HPP_
