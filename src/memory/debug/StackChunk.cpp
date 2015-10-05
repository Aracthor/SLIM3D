#include "slim/debug/exit.hh"

namespace slim
{
namespace memory
{

void*
StackChunk::alloc(std::size_t size)
{
    if (m_maxSize - m_size < size + sizeof(std::size_t))
    {
	SLIM_DEBUG_EXIT("Memory overflow in stack chunk.");
    }

    *(reinterpret_cast<std::size_t*>(m_data)) = size;

    void*	ptr = m_data + sizeof(std::size_t);

    size += sizeof(std::size_t);

    m_data += size;
    m_size += size;

    return ptr;
}

void
StackChunk::free(char* ptr)
{
    ptr -= sizeof(std::size_t);
    std::size_t	size = *(reinterpret_cast<std::size_t*>(ptr)) + sizeof(std::size_t);

    if (m_data - size != ptr)
    {
	SLIM_DEBUG_EXIT("Trying to delete non-last element of StackChunk.");
    }

    m_data = ptr;
    m_size -= size;
}

}
}
