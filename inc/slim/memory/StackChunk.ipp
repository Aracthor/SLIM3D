namespace slim
{
namespace memory
{

StackChunk::StackChunk(char* data, std::size_t size) :
    Chunk(data, size)
{
}

StackChunk::~StackChunk()
{
}

}
}

#if _DEBUG
# include "debug/StackChunk.ipp"
#else
# include "release/StackChunk.ipp"
#endif
