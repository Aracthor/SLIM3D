#ifndef SLIM_MEMORY_MANAGER_HPP_
# define SLIM_MEMORY_MANAGER_HPP_

# include "slim/containers/AbstractArray.hpp"
# include "slim/core/Singleton.hpp"
# include "slim/memory/Chunk.hpp"
# include "slim/memory/units.h"

# define SLIM_MEMORY_TOTAL_SIZE	(100 * SLIM_MEMORY_MEBIBYTE)
# define SLIM_MEMORY_MAX_CHUNKS	20

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
    void*	m_memoryStart;
    char*	m_memory;
    std::size_t	m_allocated;
    containers::AbstractArray<Chunk, SLIM_MEMORY_MAX_CHUNKS>	m_chunks;
};

}
}

# include "Manager.ipp"

#endif // !SLIM_MEMORY_MANAGER_HPP_
