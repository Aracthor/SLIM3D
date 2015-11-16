#include "slim/mesh/Mesh.hpp"

namespace slim
{
namespace mesh
{

const char* const
Mesh::typeName = "mesh";


Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}


bool
Mesh::loadFromFile(const char* const path)
{
    io::VirtualFile	file = io::VirtualFile::fromRealFile(path);
    char		buffer[SLIM_MESH_FILE_LINE_BUFFER_SIZE];

    
}

void
Mesh::unloadData()
{
}

}
}
