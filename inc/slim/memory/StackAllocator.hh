#ifndef SLIM_MEMORY_STACK_ALLOCATOR_HH_
# define SLIM_MEMORY_STACK_ALLOCATOR_HH_

# include <cstdint>
# include <new>

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
    void	init(uint64_t size);
    void	destroy();
    void*	alloc(uint64_t size);
    void	free(void* ptr);
    CheckPoint	saveCheckPoint() const;
    void	backToCheckPoint(const CheckPoint point);

private:
    char*	m_data = nullptr;
};

}
}

void*	operator new(std::size_t size);
void	operator delete(void* ptr) noexcept(true);

# include "StackAllocator.hpp"

#endif // !SLIM_MEMORY_STACK_ALLOCATOR_HH_
