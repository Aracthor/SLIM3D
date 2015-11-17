#include "slim/debug/LogManager.hpp"
#include "slim/memory/Manager.hpp"
#include "slim/memory/StackChunk.hpp"
#include "slim/mesh/Loader.hpp"

namespace slim
{
namespace mesh
{

Loader::Loader() :
    m_memory(memory::Manager::instance.createChunk<memory::StackChunk>(SLIM_MESH_LOADER_MEMORY, "Mesh loader"))
{
}

Loader::~Loader()
{
}


bool
Loader::loadFile(io::VirtualFile& file, FileLoader::Data& dest)
{
    containers::String	extention(file.getExtention());

    if (m_loaders.find(extention) == m_loaders.end())
    {
	debug::LogManager::instance.assets.error << "Unrecognized mesh format '" << extention << '\'' << debug::LogStream::endline;
	return false;
    }
    return m_loaders[extention]->readFile(file, dest);
}

void
Loader::deleteData(FileLoader::Data& data)
{
    if (data.indices != nullptr)
    {
	m_memory.free(data.indices);
    }
    if (data.normals != nullptr)
    {
	m_memory.free(data.normals);
    }
    if (data.colors != nullptr)
    {
	m_memory.free(data.colors);
    }
    if (data.positions != nullptr)
    {
	m_memory.free(data.positions);
    }
}

}
}
