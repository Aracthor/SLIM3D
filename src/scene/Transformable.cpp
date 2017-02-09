#include "slim/scene/Transformable.hpp"

namespace slim
{
namespace scene
{

Transformable::Transformable() :
    m_position(0, 0, 0),
    m_rotation(0, 0, 0),
    m_scale(1, 1, 1),
    m_updated(false)
{
}

Transformable::Transformable(const Transformable& reference) :
    m_position(reference.getPosition()),
    m_rotation(reference.getRotation()),
    m_scale(reference.getScale()),
    m_updated(false)
{
}

Transformable::~Transformable()
{
}


void
Transformable::translate(const Vector3& translation)
{
    m_position += translation;
    m_updated = false;
}

void
Transformable::addRotation(const Vector3& rotation)
{
    m_rotation += rotation;
    m_updated = false;
}

void
Transformable::scale(const Vector3& scale)
{
    m_scale *= scale;
    m_updated = false;
}

void
Transformable::setPosition(const Vector3& position)
{
    m_position = position;
    m_updated = false;
}

void
Transformable::setRotation(const Vector3& rotation)
{
    m_rotation = rotation;
    m_updated = false;
}

void
Transformable::setScale(const Vector3& scale)
{
    m_scale = scale;
    m_updated = false;
}


void
Transformable::calcMatrix()
{
    m_matrix.setIdentity();
    this->applyTransformationsToMatrix();
}

void
Transformable::calcMatrix(const Matrix4x4& parentMatrix)
{
    m_matrix = parentMatrix;
    this->applyTransformationsToMatrix();
}


void
Transformable::applyTransformationsToMatrix()
{
    m_updated = true;
    m_matrix.translate(m_position);
    m_matrix.scale(m_scale);
    m_matrix.rotateX(m_rotation.x);
    m_matrix.rotateY(m_rotation.y);
    m_matrix.rotateZ(m_rotation.z);
}

}
}
