#include "slim/maths/lib.hpp"

namespace slim
{
namespace maths
{

template <typename T>
Box<T>::Box(T x, T y, T z) :
    m_min(x, y, z),
    m_max(x, y, z)
{
}

template <typename T>
Box<T>::Box(const Vector3<T>& point) :
    m_min(point),
    m_max(point)
{
}

template <typename T>
Box<T>::Box(const Box<T>& box)
{
    m_min = box.getMin();
    m_max = box.getMax();
}

template <typename T>
Box<T>::~Box()
{
}


template <typename T>
const Vector3<T>&
Box<T>::getMin() const
{
    return m_min;
}

template <typename T>
const Vector3<T>&
Box<T>::getMax() const
{
    return m_max;
}

template <typename T>
T
Box<T>::getWidth() const
{
    return m_max.x - m_min.x;
}

template <typename T>
T
Box<T>::getHeight() const
{
    return m_max.y - m_min.y;
}

template <typename T>
T
Box<T>::getDepth() const
{
    return m_max.z - m_min.z;
}


template <typename T>
bool
Box<T>::contains(T x, T y, T z) const
{
    return (x >= m_min.x && x <= m_max.x &&
	    y >= m_min.y && y <= m_max.y &&
	    z >= m_min.z && z <= m_max.z);
}

template <typename T>
bool
Box<T>::contains(const Vector3<T>& point) const
{
    return this->contains(point.x, point.y, point.z);
}

template <typename T>
bool
Box<T>::contains(const Box<T>& box) const
{
    return (this->isPointIniside(box.getMin()) && this->isPointInside(box.getMax()));
}

template <typename T>
bool
Box<T>::intersects(const Box<T>& box) const
{
    return (this->isPointIniside(box.getMin()) || this->isPointInside(box.getMax()) || box.contains(*this));
}


template <typename T>
void
Box<T>::reset(T x, T y, T z)
{
    m_min.set(x, y, z);
    m_max.set(x, y, z);
}

template <typename T>
void
Box<T>::reset(const Vector3<T>& point)
{
    m_min.set(point);
    m_max.set(point);
}

template <typename T>
void
Box<T>::addPoint(T x, T y, T z)
{
    m_min.x = SLIM_MATHS_MIN(m_min.x, x);
    m_min.y = SLIM_MATHS_MIN(m_min.y, y);
    m_min.z = SLIM_MATHS_MIN(m_min.z, z);
    m_max.x = SLIM_MATHS_MAX(m_max.x, x);
    m_max.y = SLIM_MATHS_MAX(m_max.y, y);
    m_max.z = SLIM_MATHS_MAX(m_max.z, z);
}

template <typename T>
void
Box<T>::addPoint(const Vector3<T>& point)
{
    this->addPoint(point.x, point.y, point.z);
}

template <typename T>
void
Box<T>::addBox(const Box<T>& box)
{
    this->addPoint(box.getMin());
    this->addPoint(box.getMax());
}

}
}
