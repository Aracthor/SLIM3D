#include "slim/maths/lib.hpp"

namespace slim
{
namespace maths
{

Box::Box()
{
}

Box::Box(const Box<T>& box)
{
    this->reset();
    this->addBox(box);
}

Box::~Box()
{
}


const Vector3<T>&
Box::getMin() const
{
    return m_min;
}

const Vector3<T>&
Box::getMax() const
{
    return m_max;
}

T
Box::getWidth() const
{
    return m_max.x - m_min.x;
}

T
Box::getHeight() const
{
    return m_max.y - m_min.y;
}

T
Box::getDepth() const
{
    return m_max.z - m_min.z;
}


bool
Box::contains(const Vector3<T>& point) const
{
    return (point.x >= m_min.x && point.x <= m_max.x &&
	    point.y >= m_min.y && point.y <= m_max.y &&
	    point.z >= m_min.z && point.z <= m_max.z);
}

bool
Box::contains(const Box<T>& box) const
{
    return (this->isPointIniside(box.getMin()) && this->isPointInside(box.getMax()));
}

bool
Box::intersects(const Box<T>& box) const
{
    return (this->isPointIniside(box.getMin()) || this->isPointInside(box.getMax()) || box.contains(*this));
}


void
Box::reset()
{
    m_min.set(0);
    m_max.set(0);
}

void
Box::addPoint(const Vector3<T>& point)
{
    m_min.x = SLIM_MATHS_MIN(m_min.x, point.x);
    m_min.y = SLIM_MATHS_MIN(m_min.y, point.y);
    m_min.z = SLIM_MATHS_MIN(m_min.z, point.z);
    m_max.x = SLIM_MATHS_MAX(m_max.x, point.x);
    m_max.y = SLIM_MATHS_MAX(m_max.y, point.y);
    m_max.z = SLIM_MATHS_MAX(m_max.z, point.z);
}

void
Box::addBox(const Box<T>& box)
{
    this->addPoint(m_min);
    this->addPoint(m_max);
}

}
}
