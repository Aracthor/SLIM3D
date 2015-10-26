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
# include "debug/ArenaChunk.ipp"
#else
# include "release/ArenaChunk.ipp"
#endif
