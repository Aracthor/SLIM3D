#include "slim/debug/assert.hpp"

namespace slim
{
namespace scene
{

const Vector3&
Transformable::getPosition() const
{
    return m_position;
}

const Vector3&
Transformable::getRotation() const
{
    return m_rotation;
}

const Vector3&
Transformable::getScale() const
{
    return m_scale;
}

bool
Transformable::isUpdated() const
{
    return m_updated;
}

const Matrix4x4&
Transformable::getTransformationMatrix() const
{
    SLIM_DEBUG_ASSERT(m_updated == true);
    return m_matrix;
}

}
}
