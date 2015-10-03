#include "slim/debug/exit.hh"

namespace slim
{
namespace memory
{

void*
StackAllocator::alloc(uint64_t size)
{
    if (!m_data)
    {
	SLIM_DEBUG_EXIT("Trying to use allocator without initialization.");
    }

    void*	ptr = m_data;

    m_index += size;
    m_data += size;

    return ptr;
}

void
StackAllocator::free(uint64_t size)
{
    if (!m_data)
    {
	SLIM_DEBUG_EXIT("Trying to use allocator without initialization.");
    }

    if (size > m_index)
    {
	SLIM_DEBUG_EXIT("Critical memory error: free larger than total remaining allocated size.");
    }

    m_index -= size;
    m_data -= size;
}

StackAllocator::CheckPoint
StackAllocator::saveCheckPoint() const
{
    return m_data;
}

void
StackAllocator::backToCheckPoint(const CheckPoint point)
{
    m_data = point;
}

}
}
