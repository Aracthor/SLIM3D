#include "slim/camera/FreeFly.hpp"
#include "slim/camera/FreeFlyListeners.hpp"
#include "slim/maths/Helper.hpp"

namespace slim
{
namespace camera
{

FreeFly::FreeFly(window::Window* window, float fov, float rangeMin, float rangeMax) :
    Perspective(window->getWidth(), window->getHeight(), fov, rangeMin, rangeMax)
{
    this->recalcVectors();
    this->registerEvents(window->getEventsManager());
}

FreeFly::FreeFly(const FreeFly& reference) :
    Perspective(reference),
    m_inertia(reference.getInertia()),
    m_speed(reference.getSpeed()),
    m_sensitivity(reference.getSensitivity())
{
    this->recalcVectors();
}

FreeFly::~FreeFly()
{
}


void
FreeFly::rotateX(float angle)
{
    m_angleX += angle * m_sensitivity;
}

void
FreeFly::rotateY(float angle)
{
    m_angleY += angle * m_sensitivity;
    if (m_angleY > SLIM_CAMERA_FREE_FLY_MAX_ANGLE_Y)
    {
	m_angleY = SLIM_CAMERA_FREE_FLY_MAX_ANGLE_Y;
    }
    else if (m_angleY < -SLIM_CAMERA_FREE_FLY_MAX_ANGLE_Y)
    {
	m_angleY = -SLIM_CAMERA_FREE_FLY_MAX_ANGLE_Y;
    }
}


void
FreeFly::registerEvents(events::Manager& manager)
{
    manager.addKeyListener<freefly::MoveFront>(*this, events::keyboard::w);
    manager.addKeyListener<freefly::MoveBack>(*this, events::keyboard::s);
    manager.addKeyListener<freefly::MoveRight>(*this, events::keyboard::d);
    manager.addKeyListener<freefly::MoveLeft>(*this, events::keyboard::a);
    manager.addMouseMovementListener<freefly::MouseMovement>(*this);
}


void
FreeFly::update(time::Clock::time elapsedTime)
{
    m_position += m_move * m_speed * elapsedTime;
    m_move *= m_inertia;
    this->recalcVectors();
}


void
FreeFly::recalcVectors()
{
    m_forward.x = SLIM_MATHS_COS(m_angleY) * SLIM_MATHS_COS(m_angleX);
    m_forward.y = SLIM_MATHS_COS(m_angleY) * SLIM_MATHS_SIN(m_angleX);
    m_forward.z = SLIM_MATHS_SIN(m_angleY);

    m_left = m_forward * m_up;
    m_left.normalize();

    m_target = m_position + m_forward;
}

}
}
