#include "slim/maths/lib.hpp"

namespace slim
{
namespace maths
{

template <typename T>
Vector3<T>::Vector3()
{
}

template <typename T>
Vector3<T>::Vector3(T x, T y, T z)
{
    this->set(x, y, z);
}

template <typename T>
Vector3<T>::Vector3(const Vector2<T>& vector2, T z)
{
    this->set(vector2, z);
}

template <typename T>
Vector3<T>::Vector3(const Vector3<T>& vector)
{
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
}

template <typename T>
Vector3<T>::~Vector3()
{
}


template <typename T>
bool
Vector3<T>::equals(const Vector3<T>& vector) const
{
    return (this->x == vector.x && this->y == vector.y && this->z == vector.z);
}

template <typename T>
T
Vector3<T>::getNorm() const
{
    return (lib::sqrt(this->getSquaredNorm()));
}

template <typename T>
T
Vector3<T>::getSquaredNorm() const
{
    return (x * x + y * y + z * z);
}

template <typename T>
T
Vector3<T>::getDotProduct(const Vector3<T>& vector) const
{
    return (this->x * vector.x + this->y * vector.y + this->z * vector.z);
}


template <typename T>
void
Vector3<T>::setAllElements(T n)
{
    x = n;
    y = n;
    z = n;
}

template <typename T>
void
Vector3<T>::normalize()
{
    T norm = this->getNorm();

    x /= norm;
    y /= norm;
    z /= norm;
}

template <typename T>
void
Vector3<T>::set(T x, T y, T z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

template <typename T>
void
Vector3<T>::set(const Vector2<T>& vector2, T z)
{
    this->x = vector2.x;
    this->y = vector2.y;
    this->z = z;
}


template <typename T>
Vector3<T>&
Vector3<T>::addTo(const Vector3<T>& vector)
{
    this->x += vector.x;
    this->y += vector.y;
    this->z += vector.z;

    return *this;
}

template <typename T>
Vector3<T>&
Vector3<T>::subTo(const Vector3<T>& vector)
{
    this->x -= vector.x;
    this->y -= vector.y;
    this->z -= vector.z;

    return *this;
}

template <typename T>
Vector3<T>&
Vector3<T>::vectorProductTo(const Vector3<T>& vector)
{
    T	x, y, z;

    x = this->y * vector.z - this->z * vector.y;
    y = this->z * vector.x - this->x * vector.z;
    z = this->x * vector.y - this->y * vector.x;
    this->x = x;
    this->y = y;
    this->z = z;

    return *this;
}

template <typename T>
Vector3<T>&
Vector3<T>::scaleTo(T n)
{
    this->x *= n;
    this->y *= n;
    this->z *= n;

    return *this;
}

template <typename T>
Vector3<T>&
Vector3<T>::unscaleTo(T n)
{
    this->x /= n;
    this->y /= n;
    this->z /= n;

    return *this;
}

template <typename T>
Vector3<T>&
Vector3<T>::lerpInterpolation(const Vector3<T>& vector, T ratio)
{
    this->x = lib::lerp(this->x, vector.x, ratio);
    this->y = lib::lerp(this->y, vector.y, ratio);
    this->z = lib::lerp(this->z, vector.z, ratio);

    return *this;
}


template <typename T>
const T*
Vector3<T>::asArray() const
{
    return reinterpret_cast<const T*>(this);
}


template <typename T>
Vector3<T>
Vector3<T>::add(const Vector3<T>& vector) const
{
    return Vector3<T>(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}

template <typename T>
Vector3<T>
Vector3<T>::sub(const Vector3<T>& vector) const
{
    return Vector3<T>(this->x - vector.x, this->y - vector.y, this->z - vector.z);
}

template <typename T>
Vector3<T>
Vector3<T>::vectorProduct(const Vector3<T>& vector) const
{
    return Vector3<T>(this->y * vector.z - this->z * vector.y,
		      this->z * vector.x - this->x * vector.z,
		      this->x * vector.y - this->y * vector.x);
}

template <typename T>
Vector3<T>
Vector3<T>::scale(T n) const
{
    return Vector3<T>(x * n, y * n, z * n);
}

template <typename T>
Vector3<T>
Vector3<T>::unscale(T n) const
{
    return Vector3<T>(x / n, y / n, z / n);
}


template <typename T>
Vector3<T>
Vector3<T>::operator-() const
{
    return Vector3<T>(-x, -y, -z);
}


template <typename T>
Vector3<T>&
Vector3<T>::operator+=(const Vector3<T>& vector)
{
    return this->addTo(vector);
}

template <typename T>
Vector3<T>&
Vector3<T>::operator-=(const Vector3<T>& vector)
{
    return this->subTo(vector);
}

template <typename T>
Vector3<T>&
Vector3<T>::operator*=(const Vector3<T>& vector)
{
    return this->vectorProductTo(vector);
}

template <typename T>
Vector3<T>&
Vector3<T>::operator*=(T n)
{
    return this->scaleTo(n);
}

template <typename T>
Vector3<T>&
Vector3<T>::operator/=(T n)
{
    return this->unscaleTo(n);
}

template <typename T>
Vector3<T>
Vector3<T>::operator+(const Vector3<T>& vector) const
{
    return this->add(vector);
}

template <typename T>
Vector3<T>
Vector3<T>::operator-(const Vector3<T>& vector) const
{
    return this->sub(vector);
}

template <typename T>
Vector3<T>
Vector3<T>::operator*(const Vector3<T>& vector) const
{
    return this->vectorProduct(vector);
}

template <typename T>
Vector3<T>
Vector3<T>::operator*(T n) const
{
    return this->scale(n);
}

template <typename T>
Vector3<T>
Vector3<T>::operator/(T n) const
{
    return this->unscale(n);
}

template <typename T>
bool
Vector3<T>::operator==(const Vector3<T>& vector) const
{
    return this->equals(vector);
}

template <typename T>
bool
Vector3<T>::operator!=(const Vector3<T>& vector) const
{
    return !this->equals(vector);
}


template <typename T>
Vector3<T>&
Vector3<T>::operator=(const Vector3<T>& vector)
{
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;

    return *this;
}


template <typename T>
T
Vector3<T>::operator[](unsigned int index) const
{
    return ((reinterpret_cast<const T*>(this))[index]);
}

template <typename T>
T&
Vector3<T>::operator[](unsigned int index)
{
    return ((reinterpret_cast<T*>(this))[index]);
}


template <typename T>
template <typename U>
Vector3<T>::operator	Vector3<U>() const
{
    return Vector3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z));
}

}
}

#ifdef _DEBUG
template <typename T>
std::ostream&
operator<<(std::ostream& stream, const slim::maths::Vector3<T>& vector)
{
    stream << '(' << vector.x << ", " << vector.y << ", " << vector.z << ')';
    return stream;
}
#endif // _DEBUG
