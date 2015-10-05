#include "slim/memory/StackChunk.hh"

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
# include "debug/StackChunk.cpp"
#else
# include "release/StackChunk.cpp"
#endif
