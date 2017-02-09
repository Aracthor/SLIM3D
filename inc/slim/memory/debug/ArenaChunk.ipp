#include "slim/attributes.h"
#include "slim/debug/exit.hpp"

namespace slim
{
namespace memory
{

void*
ArenaChunk::realloc(void* ptr, std::size_t size)
{
    if (ptr == m_lastAllocated && ptr != nullptr)
    {
	void*	newPtr;

	this->loadCheckpoint(static_cast<Checkpoint>(ptr));
	newPtr = this->alloc(size);

	return newPtr;
    }
    else
    {
	return Chunk::realloc(ptr, size);
    }
}

void*
ArenaChunk::alloc(std::size_t size)
{
    if (m_maxSize - m_size < size)
    {
	SLIM_DEBUG_EXIT("Memory overflow in arena chunk \"", m_name, "\".");
    }

    void*	ptr = m_data;

    m_data += size;
    m_size += size;
    m_lastAllocated = ptr;

    return ptr;
}

void
ArenaChunk::free(SLIM_CORE_UNUSED(char*, ptr))
{
}

}
}
