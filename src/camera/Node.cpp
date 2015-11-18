#include "slim/camera/Node.hpp"

namespace slim
{
namespace camera
{

Node::Node(memory::Chunk& memory, const char* name, Node* parent, Camera* camera) :
    scene::Node(memory, name, parent),
    m_camera(camera)
{
}

Node::~Node()
{
    this->destroyCamera();
}


void
Node::updateData(time::Clock::time elapsedTime)
{
    if (m_camera)
    {
	m_camera->update(elapsedTime);
    }
}

}
}
