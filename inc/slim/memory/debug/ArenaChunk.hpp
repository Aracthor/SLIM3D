#include "slim/core/attributes.h"
#include "slim/debug/exit.hh"

namespace slim
{
namespace memory
{

void*
ArenaChunk::alloc(std::size_t size)
{
    if (m_maxSize - m_size < size)
    {
	SLIM_DEBUG_EXIT("Memory overflow in arena chunk.");
    }

    void*	ptr = m_data;

    m_data += size;
    m_size += size;

    return ptr;
}

void
ArenaChunk::free(SLIM_CORE_UNUSED(char*, ptr))
{
}

}
}
