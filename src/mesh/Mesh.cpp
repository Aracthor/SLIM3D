#include "slim/mesh/Mesh.hpp"
#include "slim/io/VirtualFile.hpp"

namespace slim
{
namespace mesh
{

const char* const
Mesh::typeName = "mesh";


Mesh::Mesh(const char* name) :
    assets::SingleFileAsset(Mesh::typeName, name, name)
{
}

Mesh::~Mesh()
{
}


bool
Mesh::loadFromFile(const char* const path)
{
    io::VirtualFile	file = io::VirtualFile::fromRealFile(path);
}

void
Mesh::unloadData()
{
}

}
}
