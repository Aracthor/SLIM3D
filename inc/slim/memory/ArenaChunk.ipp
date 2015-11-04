namespace slim
{
namespace memory
{

ArenaChunk::ArenaChunk(char* data, std::size_t size, const char* name) :
    Chunk(data, size, name)
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
