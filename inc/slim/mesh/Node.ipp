#include "slim/debug/assert.hpp"

namespace slim
{
namespace mesh
{

const Mesh*
Node::getMesh() const
{
    return m_mesh;
}

Mesh*
Node::getMesh()
{
    return m_mesh;
}


void
Node::setNodeAssetNeeded()
{
    SLIM_DEBUG_ASSERT(m_mesh != nullptr);
    m_mesh->setNeeded(true);
}

}
}
