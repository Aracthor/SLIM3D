#include "slim/debug/exit.hh"

#include <cstdlib>

namespace slim
{
namespace memory
{

StackAllocator
StackAllocator::instance;


StackAllocator::StackAllocator()
{
}

StackAllocator::~StackAllocator()
{
    if (m_data)
    {
	this->destroy();
    }
}


void
StackAllocator::init(uint64_t size)
{
    if (m_data)
    {
	SLIM_DEBUG_EXIT("Trying to initialize already initalized allocator.");
    }
    m_data = static_cast<char*>(malloc(size));
    if (!m_data)
    {
	SLIM_DEBUG_EXIT("Alloc failed in allocator initialization.");
    }
}

void
StackAllocator::destroy()
{
    if (!m_data)
    {
	SLIM_DEBUG_EXIT("Trying to destroy non initialized allocator.");
    }
    free(m_data);
    m_data = nullptr;
}

void*
StackAllocator::alloc(uint64_t size)
{
    void*	ptr = m_data;
    m_data += size;

    uint64_t*	sizeHeader = reinterpret_cast<uint64_t*>(m_data);
    *sizeHeader = size;
    m_data += sizeof(*sizeHeader);

    return ptr;
}

void
StackAllocator::free(void* ptr)
{
    m_data = m_data - *(reinterpret_cast<uint64_t*>(m_data) - 1) - sizeof(uint64_t);
}

StackAllocator::CheckPoint*
StackAllocator::saveCheckPoint() const
{
    CheckPoint*	point = new CheckPoint();

    point->m_dataPoint = m_data;

    return point;
}

void
StackAllocator::backToCheckPoint(const CheckPoint* point)
{
    m_data = point->m_dataPoint;
}

}
}

void*
operator new(std::size_t size)
{
    return slim::memory::StackAllocator::instance.alloc(size);
}

void
operator delete(void* ptr) noexcept(true)
{
    slim::memory::StackAllocator::instance.free(ptr);
}
