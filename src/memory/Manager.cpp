#include "slim/memory/Manager.hpp"

#include <cstdlib>

namespace slim
{
namespace memory
{

const std::size_t
Manager::size = SLIM_MEMORY_TOTAL_SIZE;

Manager
Manager::instance;


Manager::Manager()
{
}

Manager::~Manager()
{
}


bool
Manager::onInit()
{
    bool	valid;

    m_memoryStart = malloc(Manager::size);
    m_memory = static_cast<char*>(m_memoryStart);

    valid = (m_memoryStart != nullptr);
    if (valid)
    {
	m_managerChunk = reinterpret_cast<ChunkType*>(m_memory);
	m_memory += sizeof(ChunkType);
	new (m_managerChunk) ChunkType(m_memory, SLIM_MEMORY_MANAGER_CHUNK_SIZE, "Memory manager");
	m_memory += SLIM_MEMORY_MANAGER_CHUNK_SIZE;

	m_chunksNumber = 1;
	m_chunks = m_managerChunk->alloc<Chunk*>(sizeof(Chunk*) * 1);
	m_chunks[0] = m_managerChunk;
    }

    return !valid;
}

void
Manager::onDestroy()
{
    free(m_memoryStart);
}

}
}
