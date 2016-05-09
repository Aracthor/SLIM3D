#include "slim/mesh/Node.hpp"

namespace slim
{
namespace mesh
{

Node::Node(memory::Chunk& memory, const char* name, scene::Node* parent, Mesh* mesh) :
    scene::Node(memory, name, parent),
    m_mesh(mesh)
{
}

Node::~Node()
{
}


void
Node::updateData(SLIM_CORE_UNUSED(time::Clock::time, elapsedTime))
{
}

}
}
