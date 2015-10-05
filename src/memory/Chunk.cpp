#include "slim/memory/Chunk.hh"

namespace slim
{
namespace memory
{

Chunk::Chunk(void* data, std::size_t size) :
    m_data(data),
    m_size(size)
{
}

Chunk::~Chunk()
{
}

}
}
