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
    StackChunk(char* data, std::size_t size);
    ~StackChunk();

public:
    void*	alloc(std::size_t size) override;
    void	free(char* ptr) override;
};

}
}

#endif // !SLIM_MEMORY_STACK_CHUNK_HH_
