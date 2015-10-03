#ifndef SLIM_MEMORY_STACK_ALLOCATOR_HH_
# define SLIM_MEMORY_STACK_ALLOCATOR_HH_

# include <cstdint>
# include <new>

# include "slim/core/attributes.h"
# include "slim/debug/debug_modes.h"

namespace slim
{
namespace memory
{

class		StackAllocator
{
public:
    typedef char*		CheckPoint;

public:
    static StackAllocator	instance;

private:
    StackAllocator();
    ~StackAllocator();

public:
    void		init(uint64_t size);
    void		destroy();
    inline void*	alloc(uint64_t size);
    inline void		free(uint64_t size);
    inline CheckPoint	saveCheckPoint() const;
    inline void		backToCheckPoint(const CheckPoint point);

private:
    char*		m_data = nullptr;
# if SLIM_DEBUG_MEMORY_MODE
    uint64_t		m_index;
# endif // SLIM_DEBUG_MEMORY_MODE
};

}
}

SLIM_CORE_NORETURN void*	operator new(std::size_t size);
SLIM_CORE_NORETURN void		operator delete(void* ptr) noexcept(true);

# if SLIM_DEBUG_MEMORY_MODE
#  include "debug/StackAllocator.hpp"
# else
#  include "release/StackAllocator.hpp"
# endif

#endif // !SLIM_MEMORY_STACK_ALLOCATOR_HH_
