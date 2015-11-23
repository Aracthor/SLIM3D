#include "slim/debug/LogManager.hpp"
#include "slim/memory/Manager.hpp"
#include "slim/memory/StackChunk.hpp"
#include "slim/mesh/Loader.hpp"
#include "slim/mesh/ObjLoader.hpp"

namespace slim
{
namespace mesh
{

Loader::Loader() :
    m_memory(memory::Manager::instance.createChunk<memory::StackChunk>(SLIM_MESH_LOADER_MEMORY, "Mesh loader"))
{
    m_loaders[containers::ConstString("obj")] = m_memory.create<ObjLoader>(m_memory);

    m_checkpoint = m_memory.saveCheckpoint();
}

Loader::~Loader()
{
    m_memory.loadCheckpoint(m_checkpoint);
    m_memory.destroy(m_loaders[containers::ConstString("obj")]);
}


bool
Loader::loadFile(io::VirtualFile& file, FileLoader::Data& dest)
{
    containers::ConstString	extention(file.getExtention());

    m_memory.loadCheckpoint(m_checkpoint);

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
    if (data.vertices != nullptr)
    {
	m_memory.free(data.vertices);
    }
}

}
}
