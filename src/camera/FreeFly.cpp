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
FreeFly::registerEvents(events::Manager& manager)
{
    manager.addKeyListener(new freefly::MoveFront(*this), events::keyboard::W);
    manager.addKeyListener(new freefly::MoveBack(*this), events::keyboard::S);
    // TODO other moves
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

    m_target = m_position - m_forward;
}

}
}
