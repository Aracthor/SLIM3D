namespace slim
{
namespace memory
{

void*
StackChunk::alloc(std::size_t size)
{
    char*	ptr = m_data;

    m_data += size;

    return ptr;
}

void
StackChunk::free(char* ptr)
{
    m_data = ptr;
}

}
}
