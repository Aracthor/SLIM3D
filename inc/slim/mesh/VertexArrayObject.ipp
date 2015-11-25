#include "slim/debug/assert.hpp"

namespace slim
{
namespace mesh
{

void
VertexArrayObject::bind() const
{
    SLIM_DEBUG_ASSERT(m_id != 0);
    glBindVertexArray(m_id);
}

void
VertexArrayObject::unbind() const
{
    glBindVertexArray(0);
}


bool
VertexArrayObject::useIndices() const
{
    return m_useIndices;
}

unsigned int
VertexArrayObject::getSize() const
{
    return m_size;
}

}
}
