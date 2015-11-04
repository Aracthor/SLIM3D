namespace slim
{
namespace memory
{

template <class CHUNK>
CHUNK&
Manager::createChunk(std::size_t size, const char* name)
{
    char*	data = static_cast<char*>(m_memory);

    m_chunks.insert<CHUNK>(data, size, name);
    m_memory += size;

    return m_chunks.operator[]<CHUNK>(m_chunks.getSize() - 1);
}

}
}
