#include "slim/memory/StackChunk.hpp"

#include "slim/string.h"

namespace slim
{
namespace memory
{

StackChunk::StackChunk(char* data, std::size_t size, const char* name) :
    Chunk::Chunk(data, size, name)
{
}

StackChunk::~StackChunk()
{
}


void*
StackChunk::realloc(void* ptr, std::size_t size)
{
    void*	newPtr;

    if (ptr != nullptr)
    {
	unsigned char	data[size];

	memcpy(data, ptr, size);
	Chunk::free(ptr);
	newPtr = this->alloc(size);
	memcpy(newPtr, data, size);
    }
    else
    {
	newPtr = this->alloc(size);
    }

    return newPtr;
}

}
}
