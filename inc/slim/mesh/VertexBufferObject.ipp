#include "slim/debug/assert.hpp"

namespace slim
{
namespace mesh
{

void
VertexBufferObject::bind() const
{
    SLIM_DEBUG_ASSERT(m_id != 0);
    glBindBuffer(m_type, m_id);
}

void
VertexBufferObject::unbind() const
{
    SLIM_DEBUG_ASSERT(m_id != 0);
    glBindBuffer(m_type, 0);
}

}
}
