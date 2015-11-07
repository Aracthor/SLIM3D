#include "slim/scene/Node.hpp"

namespace slim
{
namespace scene
{

Node::Node(const char* name, Node* parent) :
    m_name(name),
    m_parent(parent)
{
}

Node::~Node()
{
}

}
}
