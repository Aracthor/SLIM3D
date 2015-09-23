#include "slim/debug/assert.hh"

#include <cstring>

namespace slim
{
namespace resources
{

const byte*
VirtualFile::getData() const
{
    return m_data;
}

unsigned int
VirtualFile::getSize() const
{
    return m_size;
}


template <typename T>
void
VirtualFile::readPureData(T& data)
{
    SLIM_DEBUG_ASSERT(m_index + sizeof(T) <= m_size);
    memcpy(&data, &m_data[m_index], sizeof(T));
    m_index += sizeof(T);
}

}
}
