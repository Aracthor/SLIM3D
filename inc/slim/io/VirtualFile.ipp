#include "slim/debug/assert.hpp"

#include <cstring>

namespace slim
{
namespace io
{

unsigned int
VirtualFile::getSize() const
{
    return m_size;
}

const char*
VirtualFile::getName() const
{
    return m_name;
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
