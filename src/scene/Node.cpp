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
Node::update(time::Clock::time elapsedTime)
{
    if (!this->isUpdated())
    {
	this->updateMatrix();
    }
    this->updateData(elapsedTime);
    m_children.forEach(&Node::updateData, elapsedTime);
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
