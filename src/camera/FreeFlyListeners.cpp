#include "slim/camera/FreeFlyListeners.hpp"

namespace slim
{
namespace camera
{

namespace freefly
{

Listener::Listener(FreeFly& camera) :
    m_camera(camera)
{
}

Listener::~Listener()
{
}


MoveFront::MoveFront(FreeFly& camera) :
    Listener(camera)
{
}

MoveFront::~MoveFront()
{
}


void
MoveFront::onEvent()
{
    m_camera.advance(1.0);
}


MoveBack::MoveBack(FreeFly& camera) :
    Listener(camera)
{
}

MoveBack::~MoveBack()
{
}


void
MoveBack::onEvent()
{
    m_camera.advance(-1.0);
}

}

}
}
