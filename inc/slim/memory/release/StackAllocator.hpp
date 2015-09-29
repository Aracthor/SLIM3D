namespace slim
{
namespace memory
{

void*
StackAllocator::alloc(uint64_t size)
{
    void*	ptr = m_data;

    m_data += size;

    return ptr;
}

void
StackAllocator::free(uint64_t size)
{
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
