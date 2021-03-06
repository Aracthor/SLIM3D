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
    inline ArenaChunk(char* data, std::size_t size, const char* name);
    inline ~ArenaChunk();

public:
    inline void*	realloc(void* ptr, std::size_t size) override;
    inline void*	alloc(std::size_t size) override;
    inline void		free(char* ptr) override;

private:
    void*		m_lastAllocated = nullptr;
};

}
}

# include "ArenaChunk.ipp"

#endif // !SLIM_MEMORY_ARENA_CHUNK_HPP_
