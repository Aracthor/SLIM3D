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
Camera::getViewMatrix(Matrix4x4& matrix) const
{
    if (m_position == m_target)
    {
	debug::LogManager::instance.graphics.warning << "Position and target are equals for active camera of this frame!" << debug::LogStream::endline;
	matrix.setIdentity();
    }
    else
    {
	matrix.lookAt(m_position, m_target, m_up);
    }
}

}
}
