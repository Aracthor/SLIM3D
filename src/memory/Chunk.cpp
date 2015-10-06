#include "slim/memory/Chunk.hpp"

namespace slim
{
namespace memory
{

Chunk::Chunk(char* data, std::size_t size) :
    m_start(data),
    m_maxSize(size)
{
    this->clear();
}

Chunk::~Chunk()
{
}


void
Chunk::clear()
{
    m_size = 0;
    m_data = m_start;
}

}
}
