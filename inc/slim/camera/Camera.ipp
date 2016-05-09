#include "slim/debug/LogManager.hpp"

namespace slim
{
namespace camera
{

const Vector3&
Camera::getPosition() const
{
    return m_position;
}

const Vector3&
Camera::getTarget() const
{
    return m_target;
}

const Vector3&
Camera::getUp() const
{
    return m_up;
}


void
Camera::setPosition(float x, float y, float z)
{
    m_position.set(x, y, z);
}

void
Camera::setPosition(const Vector3& position)
{
    m_position = position;
}

void
Camera::setTarget(float x, float y, float z)
{
    m_target.set(x, y, z);
}

void
Camera::setTarget(const Vector3& target)
{
    m_target = target;
}

void
Camera::setUp(float x, float y, float z)
{
    m_up.set(x, y, z);
}

void
Camera::setUp(const Vector3& up)
{
    m_up = up;
}

}
}
