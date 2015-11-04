namespace slim
{
namespace memory
{

StackChunk::StackChunk(char* data, std::size_t size, const char* name) :
    Chunk(data, size, name)
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
