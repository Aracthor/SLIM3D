#ifndef SLIM_MEMORY_MANAGER_HPP_
# define SLIM_MEMORY_MANAGER_HPP_

# include "slim/core/Singleton.hpp"
# include "slim/memory/ArenaChunk.hpp"
# include "slim/memory/Chunk.hpp"
# include "slim/memory/units.h"

# define SLIM_MEMORY_TOTAL_SIZE		(100 * SLIM_MEMORY_MEBIBYTE)
# define SLIM_MEMORY_MANAGER_CHUNK_SIZE	(10 * SLIM_MEMORY_KIBIBYTE)

namespace slim
{
namespace memory
{

class		Manager : public core::Singleton
{
public:
    const static std::size_t	size;
    static Manager		instance;

public:
    Manager();
    ~Manager();

public:
    template <class CHUNK> // CHUNK must inherit from slim::memory::Chunk
    CHUNK&	createChunk(std::size_t size, const char* name);

protected:
    bool	onInit() override;
    void	onDestroy() override;

private:
    typedef ArenaChunk	ChunkType;

private:
    void*		m_memoryStart;
    char*		m_memory;
    Chunk*		m_managerChunk;
    Chunk**		m_chunks;
    unsigned int	m_chunksNumber;
};

}
}

# include "Manager.ipp"

#endif // !SLIM_MEMORY_MANAGER_HPP_
