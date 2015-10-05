namespace slim
{
namespace memory
{

ArenaChunk::ArenaChunk(char* data, std::size_t size) :
    Chunk(data, size)
{
}

ArenaChunk::~ArenaChunk()
{
}

}
}

#if _DEBUG
# include "debug/ArenaChunk.hpp"
#else
# include "release/ArenaChunk.hpp"
#endif
