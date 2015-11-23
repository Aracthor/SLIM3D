#include "slim/debug/assert.hpp"
#include "slim/memory/Chunk.hpp"

#include "slim/string.h"

namespace slim
{
namespace memory
{

Chunk::Chunk(char* data, std::size_t size, const char* name) :
    m_start(data),
    m_maxSize(size),
    m_name(name)
{
    this->clear();
}

Chunk::~Chunk()
{
}


void
Chunk::clear()
{
    m_size = 0;
    m_data = m_start;
}


void*
Chunk::realloc(void* ptr, std::size_t size)
{
    void*	newPtr = this->alloc(size);

    if (ptr != nullptr)
    {
	memcpy(newPtr, ptr, size);
	this->free(ptr);
    }

    return newPtr;
}


void
Chunk::loadCheckpoint(Checkpoint checkpoint)
{
    SLIM_DEBUG_ASSERT(checkpoint >= m_start);
    std::size_t	differrence = m_data - m_start;

    m_size -= differrence;
    m_data = checkpoint;
}

}
}
