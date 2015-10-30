#ifndef SLIM_MEMORY_ARENA_CHUNK_HPP_
# define SLIM_MEMORY_ARENA_CHUNK_HPP_

# include "slim/memory/Chunk.hpp"

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

# include "ArenaChunk.ipp"

#endif // !SLIM_MEMORY_ARENA_CHUNK_HPP_
