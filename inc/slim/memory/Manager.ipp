namespace slim
{
namespace memory
{

template <class CHUNK>
CHUNK&
Manager::createChunk(std::size_t size, const char* name)
{
    char*	data = static_cast<char*>(m_memory);

    m_chunksNumber++;
    m_chunks = m_managerChunk->realloc<Chunk*>(m_chunks, sizeof(Chunk*) * m_chunksNumber);
    m_chunks[m_chunksNumber - 1] = m_managerChunk->create<CHUNK>(data, size, name);
    m_memory += size;

    return *reinterpret_cast<CHUNK*>(m_chunks[m_chunksNumber - 1]);
}

}
}
