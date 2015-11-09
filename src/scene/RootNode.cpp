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
RootNode::updateData()
{
    // A root node is perfectly static.
}

}
}
