#include "slim/scene/RootNode.hpp"

namespace slim
{
namespace scene
{

RootNode::RootNode(memory::Chunk& chunk) :
    Node(chunk, "root", nullptr)
{
}

RootNode::~RootNode()
{
}


void
RootNode::updateData(SLIM_CORE_UNUSED(time::Clock::time, elapsedTime))
{
    // A root node is perfectly static.
}

}
}
