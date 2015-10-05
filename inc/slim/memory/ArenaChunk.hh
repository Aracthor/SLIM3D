#ifndef SLIM_MEMORY_ARENA_CHUNK_HH_
# define SLIM_MEMORY_ARENA_CHUNK_HH_

# include "slim/memory/Chunk.hh"

namespace slim
{
namespace memory
{

class			ArenaChunk : public Chunk
{
public:
    inline ArenaChunk(char* data, std::size_t size);
    inline ~ArenaChunk();

public:
    inline void*	alloc(std::size_t size) override;
    inline void		free(char* ptr) override;
};

}
}

# include "ArenaChunk.hpp"

#endif // !SLIM_MEMORY_ARENA_CHUNK_HH_
