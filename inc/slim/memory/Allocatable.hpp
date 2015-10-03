#include "slim/core/attributes.h"
#include "slim/memory/StackAllocator.hh"

namespace slim
{
namespace memory
{

template <class T>
void*
Allocatable<T>::operator new(SLIM_CORE_UNUSED(std::size_t, size))
{
    return StackAllocator::instance.alloc(sizeof(T));
}

template <class T>
void
Allocatable<T>::operator delete(SLIM_CORE_UNUSED(void*, ptr))
{
    StackAllocator::instance.free(sizeof(T));
}

}
}
