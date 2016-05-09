#include "slim/camera/Camera.hpp"

namespace slim
{
namespace camera
{

Camera::Camera() :
    m_position(0, 0, 0),
    m_target(0, 0, 0),
    m_up(0, 0, 1)
{
}

Camera::Camera(const Camera& reference) :
    m_position(reference.getPosition()),
    m_target(reference.getTarget()),
    m_up(reference.getUp())
{
}

Camera::~Camera()
{
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


void
Camera::update(SLIM_CORE_UNUSED(time::Clock::time, elapsedTime))
{
    // May be overriden in a subclass.
}

}
}
