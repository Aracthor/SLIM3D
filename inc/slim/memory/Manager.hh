#ifndef SLIM_MEMORY_MANAGER_HH_
# define SLIM_MEMORY_MANAGER_HH_

# include "slim/core/Singleton.hh"
# include "slim/memory/Chunk.hh"
# include "slim/memory/units.h"

# define SLIM_MEMORY_TOTAL_SIZE	(100 * SLIM_MEMORY_MEBIBYTE)

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
    bool	onInit() override;
    void	onDestroy() override;


public:
    void*	m_memory;
    std::size_t	m_allocated;
};

}
}

# include "Manager.hpp"

#endif // !SLIM_MEMORY_MANAGER_HH_
