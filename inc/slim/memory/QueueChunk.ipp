namespace slim
{
namespace memory
{

QueueChunk::QueueChunk(char* data, std::size_t size, const char* name) :
    Chunk(data, size, name),
    m_queueStart(m_start),
    m_queueEnd(m_start)
{
}

QueueChunk::~QueueChunk()
{
}

}
}

#if _DEBUG
# include "debug/QueueChunk.ipp"
#else
# include "release/QueueChunk.ipp"
#endif
