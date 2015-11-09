#include "slim/scene/Node.hpp"

namespace slim
{
namespace scene
{

Node::Node(memory::Chunk& chunk, const char* name, Node* parent) :
    m_name(name),
    m_parent(parent),
    m_children(chunk)
{
}

Node::~Node()
{
}


void
Node::update()
{
    if (!this->isUpdated())
    {
	this->updateMatrix();
    }
    this->updateData();
    m_children.forEach(&Node::updateData);
}


void
Node::updateMatrix()
{
    if (m_parent)
    {
	this->calcMatrix();
    }
    else
    {
	this->calcMatrix(m_parent->getTransformationMatrix());
    }
    m_children.forEach(&Node::updateMatrix);
}

}
}
