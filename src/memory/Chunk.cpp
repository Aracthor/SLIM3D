#include "slim/memory/Chunk.hh"

namespace slim
{
namespace memory
{

Chunk::Chunk(char* data, std::size_t size) :
    m_data(data),
    m_size(0),
    m_maxSize(size)
{
}

Chunk::~Chunk()
{
}

}
}
