#ifndef SLIM_MEMORY_DIRTY_CHUNK_HPP_
# define SLIM_MEMORY_DIRTY_CHUNK_HPP_

# include "slim/memory/Chunk.hpp"

namespace slim
{
namespace memory
{

class	DirtyChunk : public Chunk
{
public:
    inline DirtyChunk(char* data, std::size_t size, const char* name);
    inline ~DirtyChunk();

public:
    inline void*	alloc(std::size_t size) override;
    inline void 	free(char* ptr) override;
};

}
}

# include "DirtyChunk.ipp"

#endif // !SLIM_MEMORY_DIRTY_CHUNK_HPP_
