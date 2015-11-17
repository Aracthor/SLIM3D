#ifndef SLIM_MESH_LOADER_HPP_
# define SLIM_MESH_LOADER_HPP_

# include <map> // TODO create our own

# include "slim/containers/String.hpp"
# include "slim/mesh/FileLoader.hpp"

# include "slim/memory/units.h"

# define SLIM_MESH_LOADER_MEMORY	(1 * SLIM_MEMORY_MEBIBYTE)

namespace slim
{
namespace mesh
{

class	Loader
{
public:
    Loader();
    ~Loader();

public:
    bool	loadFile(io::VirtualFile& file, FileLoader::Data& dest);
    void	deleteData(FileLoader::Data& data);

private:
    std::map<containers::String, FileLoader*>	m_loaders;
    memory::Chunk&	m_memory;
};

}
}

# include "Loader.ipp"

#endif // !SLIM_MESH_LOADER_HPP_
