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
# include "debug/StackChunk.hpp"
#else
# include "release/StackChunk.hpp"
#endif
