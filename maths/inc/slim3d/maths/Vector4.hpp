//
// Vector4.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Sat Sep  5 12:02:37 2015 Aracthor
// Last Update Sun Sep  6 12:24:45 2015 Aracthor
//

template <typename T>
Vector4<T>::Vector4()
{
}

template <typename T>
Vector4<T>::Vector4(T x, T y, T z, T w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

template <typename T>
Vector4<T>::Vector4(const Vector2<T>& vector2, T z, T w)
{
    this->set(vector2, z, w);
}

template <typename T>
Vector4<T>::Vector4(const Vector3<T>& vector3, T w)
{
    this->set(vector3, w);
}

template <typename T>
Vector4<T>::Vector4(const Vector4<T>& vector)
{
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
    this->w = vector.w;
}

template <typename T>
Vector4<T>::~Vector4()
{
}


template <typename T>
bool
Vector4<T>::equals(const Vector4<T>& vector) const
{
    return (this->x == vector.x && this->y == vector.y && this->z == vector.z && this->w == vector.w);
}

template <typename T>
T
Vector4<T>::getNorm() const
{
    return (lib::sqrt(this->getSquaredNorm()));
}

template <typename T>
T
Vector4<T>::getSquaredNorm() const
{
    return (x * x + y * y + z * z + w * w);
}


template <typename T>
void
Vector4<T>::setAllElements(T n)
{
    x = n;
    y = n;
    z = n;
    w = n;
}

template <typename T>
void
Vector4<T>::normalize()
{
    T norm = this->getNorm();

    x /= norm;
    y /= norm;
    z /= norm;
    w /= norm;
}

template <typename T>
void
Vector4<T>::set(const Vector2<T>& vector2, T z, T w)
{
    this->x = vector2.x;
    this->y = vector2.y;
    this->z = z;
    this->w = w;
}

template <typename T>
void
Vector4<T>::set(const Vector3<T>& vector3, T w)
{
    this->x = vector3.x;
    this->y = vector3.y;
    this->z = vector3.z;
    this->w = w;
}


template <typename T>
Vector4<T>&
Vector4<T>::addTo(const Vector4<T>& vector)
{
    this->x += vector.x;
    this->y += vector.y;
    this->z += vector.z;
    this->w += vector.w;

    return *this;
}

template <typename T>
Vector4<T>&
Vector4<T>::subTo(const Vector4<T>& vector)
{
    this->x -= vector.x;
    this->y -= vector.y;
    this->z -= vector.z;
    this->w -= vector.w;

    return *this;
}

template <typename T>
Vector4<T>&
Vector4<T>::scaleTo(T n)
{
    this->x *= n;
    this->y *= n;
    this->z *= n;
    this->w *= n;

    return *this;
}

template <typename T>
Vector4<T>&
Vector4<T>::unscaleTo(T n)
{
    this->x /= n;
    this->y /= n;
    this->z /= n;
    this->w /= n;

    return *this;
}


template <typename T>
Vector4<T>
Vector4<T>::add(const Vector4<T>& vector) const
{
    return Vector4<T>(this->x + vector.x, this->y + vector.y, this->z + vector.z, this->w + vector.w);
}

template <typename T>
Vector4<T>
Vector4<T>::sub(const Vector4<T>& vector) const
{
    return Vector4<T>(this->x - vector.x, this->y - vector.y, this->z - vector.z, this->w - vector.w);
}

template <typename T>
Vector4<T>
Vector4<T>::scale(T n) const
{
    return Vector4<T>(x * n, y * n, z * n, w * n);
}

template <typename T>
Vector4<T>
Vector4<T>::unscale(T n) const
{
    return Vector4<T>(x / n, y / n, z / n, w / n);
}


template <typename T>
Vector4<T>
Vector4<T>::operator-() const
{
    return Vector4<T>(-x, -y, -z, -w);
}


template <typename T>
Vector4<T>&
Vector4<T>::operator+=(const Vector4<T>& vector)
{
    return this->addTo(vector);
}

template <typename T>
Vector4<T>&
Vector4<T>::operator-=(const Vector4<T>& vector)
{
    return this->subTo(vector);
}

template <typename T>
Vector4<T>&
Vector4<T>::operator*=(T n)
{
    return this->scaleTo(n);
}

template <typename T>
Vector4<T>&
Vector4<T>::operator/=(T n)
{
    return this->unscaleTo(n);
}

template <typename T>
Vector4<T>
Vector4<T>::operator+(const Vector4<T>& vector) const
{
    return this->add(vector);
}

template <typename T>
Vector4<T>
Vector4<T>::operator-(const Vector4<T>& vector) const
{
    return this->sub(vector);
}

template <typename T>
Vector4<T>
Vector4<T>::operator*(T n) const
{
    return this->scale(n);
}

template <typename T>
Vector4<T>
Vector4<T>::operator/(T n) const
{
    return this->unscale(n);
}

template <typename T>
bool
Vector4<T>::operator==(const Vector4<T>& vector) const
{
    return this->equals(vector);
}

template <typename T>
bool
Vector4<T>::operator!=(const Vector4<T>& vector) const
{
    return !this->equals(vector);
}


template <typename T>
T
Vector4<T>::operator[](unsigned int index) const
{
    return reinterpret_cast<const T* const>(this)[index];
}

template <typename T>
T&
Vector4<T>::operator[](unsigned int index)
{
    return reinterpret_cast<T* const>(this)[index];
}


template <typename T>
template <typename U>
Vector4<T>::operator	Vector4<U>() const
{
    return Vector4<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z), static_cast<U>(w));
}
