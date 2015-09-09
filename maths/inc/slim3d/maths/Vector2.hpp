//
// Vector2.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Sat Sep  5 12:02:37 2015 Aracthor
// Last Update Thu Sep 10 00:00:15 2015 Aracthor
//

namespace slim
{
namespace maths
{

template <typename T>
Vector2<T>::Vector2()
{
}

template <typename T>
Vector2<T>::Vector2(T x, T y)
{
    this->x = x;
    this->y = y;
}

template <typename T>
Vector2<T>::Vector2(const Vector2<T>& vector)
{
    this->x = vector.x;
    this->y = vector.y;
}

template <typename T>
Vector2<T>::~Vector2()
{
}


template <typename T>
bool
Vector2<T>::equals(const Vector2<T>& vector) const
{
    return (this->x == vector.x && this->y == vector.y);
}

template <typename T>
T
Vector2<T>::getNorm() const
{
    return (lib::sqrt(this->getSquaredNorm()));
}

template <typename T>
T
Vector2<T>::getSquaredNorm() const
{
    return (x * x + y * y);
}


template <typename T>
void
Vector2<T>::setAllElements(T n)
{
    x = n;
    y = n;
}

template <typename T>
void
Vector2<T>::normalize()
{
    T norm = this->getNorm();

    x /= norm;
    y /= norm;
}


template <typename T>
Vector2<T>&
Vector2<T>::addTo(const Vector2<T>& vector)
{
    this->x += vector.x;
    this->y += vector.y;

    return *this;
}

template <typename T>
Vector2<T>&
Vector2<T>::subTo(const Vector2<T>& vector)
{
    this->x -= vector.x;
    this->y -= vector.y;

    return *this;
}

template <typename T>
Vector2<T>&
Vector2<T>::scaleTo(T n)
{
    this->x *= n;
    this->y *= n;

    return *this;
}

template <typename T>
Vector2<T>&
Vector2<T>::unscaleTo(T n)
{
    this->x /= n;
    this->y /= n;

    return *this;
}


template <typename T>
Vector2<T>
Vector2<T>::add(const Vector2<T>& vector) const
{
    return Vector2<T>(this->x + vector.x, this->y + vector.y);
}

template <typename T>
Vector2<T>
Vector2<T>::sub(const Vector2<T>& vector) const
{
    return Vector2<T>(this->x - vector.x, this->y - vector.y);
}

template <typename T>
Vector2<T>
Vector2<T>::scale(T n) const
{
    return Vector2<T>(x * n, y * n);
}

template <typename T>
Vector2<T>
Vector2<T>::unscale(T n) const
{
    return Vector2<T>(x / n, y / n);
}


template <typename T>
Vector2<T>
Vector2<T>::operator-() const
{
    return Vector2<T>(-x, -y);
}


template <typename T>
Vector2<T>&
Vector2<T>::operator+=(const Vector2<T>& vector)
{
    return this->addTo(vector);
}

template <typename T>
Vector2<T>&
Vector2<T>::operator-=(const Vector2<T>& vector)
{
    return this->subTo(vector);
}

template <typename T>
Vector2<T>&
Vector2<T>::operator*=(T n)
{
    return this->scaleTo(n);
}

template <typename T>
Vector2<T>&
Vector2<T>::operator/=(T n)
{
    return this->unscaleTo(n);
}

template <typename T>
Vector2<T>
Vector2<T>::operator+(const Vector2<T>& vector) const
{
    return this->add(vector);
}

template <typename T>
Vector2<T>
Vector2<T>::operator-(const Vector2<T>& vector) const
{
    return this->sub(vector);
}

template <typename T>
Vector2<T>
Vector2<T>::operator*(T n) const
{
    return this->scale(n);
}

template <typename T>
Vector2<T>
Vector2<T>::operator/(T n) const
{
    return this->unscale(n);
}

template <typename T>
bool
Vector2<T>::operator==(const Vector2<T>& vector) const
{
    return this->equals(vector);
}

template <typename T>
bool
Vector2<T>::operator!=(const Vector2<T>& vector) const
{
    return !this->equals(vector);
}


template <typename T>
T
Vector2<T>::operator[](unsigned int index) const
{
    return ((reinterpret_cast<const T*>(this))[index]);
}

template <typename T>
T&
Vector2<T>::operator[](unsigned int index)
{
    return ((reinterpret_cast<T*>(this))[index]);
}


template <typename T>
template <typename U>
Vector2<T>::operator	Vector2<U>() const
{
    return Vector2<U>(static_cast<U>(x), static_cast<U>(y));
}

}
}
