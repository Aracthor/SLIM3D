#ifndef SLIM_MEMORY_STACK_CHUNK_HH_
# define SLIM_MEMORY_STACK_CHUNK_HH_

# include "slim/memory/Chunk.hh"

namespace slim
{
namespace memory
{

class		StackChunk : public Chunk
{
public:
    inline StackChunk(char* data, std::size_t size);
    inline ~StackChunk();

public:
    inline void*	alloc(std::size_t size) override;
    inline void 	free(char* ptr) override;
};

}
}

# include "StackChunk.hpp"

#endif // !SLIM_MEMORY_STACK_CHUNK_HH_
