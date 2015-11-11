#include "slim/stdlib.h"
#include "slim/debug/exit.hpp"

namespace slim
{
namespace memory
{

DirtyChunk::DirtyChunk(char* data, std::size_t size, const char* name) :
    Chunk(data, size, name)
{
}

DirtyChunk::~DirtyChunk()
{
}


void*
DirtyChunk::alloc(std::size_t size)
{
    void*	ptr = malloc(size);

    if (ptr == nullptr)
    {
	SLIM_DEBUG_EXIT("malloc error");
    }

    return ptr;
}

void
DirtyChunk::free(char* ptr)
{
    ::free(ptr);
}

}
}
