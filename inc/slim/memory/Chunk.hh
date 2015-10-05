#ifndef SLIM_MEMORY_CHUNK_HH_
# define SLIM_MEMORY_CHUNK_HH_

# include <cstddef>

namespace slim
{
namespace memory
{

class	Chunk
{
public:
    Chunk(void* data, std::size_t size);
    virtual ~Chunk();

public:
    inline std::size_t	getSize() const;

protected:
    void*		m_data;
    const std::size_t	m_size;
};

}
}

# include "Chunk.hpp"

#endif // !SLIM_MEMORY_CHUNK_HH_
