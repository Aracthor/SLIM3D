#include "slim/attributes.h"

namespace slim
{
namespace memory
{

void*
ArenaChunk::alloc(std::size_t size)
{
    void*	ptr = m_data;

    m_data += size;

    return ptr;
}

void
ArenaChunk::free(SLIM_CORE_UNUSED(char*, ptr))
{
}

}
}
