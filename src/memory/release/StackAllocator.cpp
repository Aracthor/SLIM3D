#include "slim/core/attributes.h"
#include "slim/debug/exit.hh"

#include <cstdlib>

namespace slim
{
namespace memory
{

StackAllocator
StackAllocator::instance;


StackAllocator::StackAllocator()
{
}

StackAllocator::~StackAllocator()
{
    if (m_data)
    {
	this->destroy();
    }
}


void
StackAllocator::init(uint64_t size)
{
    if (m_data)
    {
	SLIM_DEBUG_EXIT("Trying to initialize already initalized allocator.");
    }

    m_data = static_cast<char*>(malloc(size));
    if (!m_data)
    {
	SLIM_DEBUG_EXIT("Alloc failed in allocator initialization.");
    }
}

void
StackAllocator::destroy()
{
    if (!m_data)
    {
	SLIM_DEBUG_EXIT("Trying to destroy non initialized allocator.");
    }
    ::free(m_data);
    m_data = nullptr;
}

}
}

SLIM_CORE_NORETURN void*
operator new(SLIM_CORE_UNUSED(std::size_t, size))
{
    SLIM_DEBUG_EXIT("Cannot allocate object not heriting from slim::memory::Allocatable.");
}

SLIM_CORE_NORETURN void
operator delete(SLIM_CORE_UNUSED(void*, ptr)) noexcept(true)
{
    SLIM_DEBUG_EXIT("Cannot allocate object not heriting from slim::memory::Allocatable.");
}
