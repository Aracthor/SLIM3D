#ifndef SLIM_MEMORY_ALLOCATABLE_HH_
# define SLIM_MEMORY_ALLOCATABLE_HH_

# include <new>

namespace slim
{
namespace memory
{

template <class T>
class	Allocatable
{
public:
    inline void*	operator new(std::size_t size);
    inline void		operator delete(void* ptr);
};

}
}

# include "Allocatable.hpp"

#endif // !SLIM_MEMORY_ALLOCATABLE_HH_
