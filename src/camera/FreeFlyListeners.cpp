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


MoveRight::MoveRight(FreeFly& camera) :
    Listener(camera)
{
}

MoveRight::~MoveRight()
{
}


void
MoveRight::onEvent()
{
    m_camera.horizontalMove(1.0);
}


MoveLeft::MoveLeft(FreeFly& camera) :
    Listener(camera)
{
}

MoveLeft::~MoveLeft()
{
}


void
MoveLeft::onEvent()
{
    m_camera.horizontalMove(-1.0);
}


MouseMovement::MouseMovement(FreeFly& camera) :
    Listener(camera)
{
}

MouseMovement::~MouseMovement()
{
}


void
MouseMovement::onEvent(const Vector2& position)
{
    Vector2	movement(window::Window::getCurrent()->getCenter());

    movement -= position;
    m_camera.rotateX(-movement.x);
    m_camera.rotateY(-movement.y);
    window::Window::getCurrent()->setCursorAtCenter();
}

}

}
}
