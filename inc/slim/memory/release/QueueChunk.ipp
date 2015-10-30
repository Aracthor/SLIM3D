namespace slim
{
namespace memory
{

void*
QueueChunk::alloc(std::size_t size)
{
    if (m_queueEnd + size + sizeof(std::size_t) >= m_data + m_maxSize)
    {
	m_size += (m_data + m_maxSize - m_queueEnd);
	m_queueEnd = m_data;
    }

    *(reinterpret_cast<std::size_t*>(m_queueEnd)) = size;

    void*	ptr = m_queueEnd + sizeof(std::size_t);

    size += sizeof(std::size_t);
    m_size += size;
    m_queueEnd += size;

    return ptr;
}

void
QueueChunk::free(char* ptr)
{
    ptr -= sizeof(std::size_t);
    std::size_t	size = *(reinterpret_cast<std::size_t*>(ptr)) + sizeof(std::size_t);

    if (m_queueStart + size >= m_data + m_maxSize)
    {
	m_size -= (m_data + m_maxSize - m_queueStart);
	m_queueStart = m_data;
    }

    m_queueStart += size;
    m_size -= size;
}

}
}
