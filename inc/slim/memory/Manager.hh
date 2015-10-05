#ifndef SLIM_MEMORY_MANAGER_HH_
# define SLIM_MEMORY_MANAGER_HH_

# include "slim/containers/AbstractArray.hh"
# include "slim/core/Singleton.hh"
# include "slim/memory/Chunk.hh"
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
    CHUNK&	createChunk(std::size_t size);

protected:
    bool	onInit() override;
    void	onDestroy() override;

private:
    char*	m_memory;
    std::size_t	m_allocated;
    containers::AbstractArray<Chunk, SLIM_MEMORY_MAX_CHUNKS>	m_chunks;
};

}
}

# include "Manager.hpp"

#endif // !SLIM_MEMORY_MANAGER_HH_
