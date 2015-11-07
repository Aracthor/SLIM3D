#ifndef SLIM_MEMORY_SMART_STACK_CHUNK_HPP_
# define SLIM_MEMORY_SMART_STACK_CHUNK_HPP_

# include "slim/memory/Chunk.hpp"

namespace slim
{
namespace memory
{

class			SmartStackChunk : public Chunk
{
public:
    inline SmartStackChunk(char* data, std::size_t size, const char* name);
    inline ~SmartStackChunk();

public:
    inline void*	alloc(std::size_t size) override;
    inline void 	free(char* ptr) override;

private:
    struct		Header
    {
	bool		free;
	std::size_t	size;
	Header*		previous;
    };

    Header*		m_lastElem;
};

}
}

# include "SmartStackChunk.ipp"

#endif // !SLIM_MEMORY_SMART_STACK_CHUNK_HPP_
