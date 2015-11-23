#include "slim/scene/Node.hpp"

namespace slim
{
namespace scene
{

Node::Node(memory::Chunk& chunk, const char* name, Node* parent) :
    m_memory(chunk),
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
Node::setAssetsNeeded()
{
    this->setNodeAssetNeeded();
    m_children.forEach(&Node::setAssetsNeeded);
}

void
Node::setNodeAssetNeeded()
{
    // May be overriden if a node has got an asset.
}


void
Node::updateMatrix()
{
    if (m_parent)
    {
	this->calcMatrix(m_parent->getTransformationMatrix());
    }
    else
    {
	this->calcMatrix();
    }
    m_children.forEach(&Node::updateMatrix);
}

}
}
