#ifndef SLIM_MEMORY_QUEUE_CHUNK_HPP_
# define SLIM_MEMORY_QUEUE_CHUNK_HPP_

# include "slim/memory/Chunk.hpp"

namespace slim
{
namespace memory
{

class	QueueChunk : public Chunk
{
public:
    inline QueueChunk(char* data, std::size_t size);
    inline ~QueueChunk();

public:
    inline void*	alloc(std::size_t size) override;
    inline void		free(char* ptr) override;

private:
    char*		m_queueStart;
    char*		m_queueEnd;
};

}
}

# include "QueueChunk.ipp"

#endif // !SLIM_MEMORY_QUEUE_CHUNK_HPP_
