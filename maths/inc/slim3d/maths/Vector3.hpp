//
// Vector3.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Sat Sep  5 12:02:37 2015 Aracthor
// Last Update Sat Sep  5 13:36:05 2015 Aracthor
//

template <typename T>
Vector3<T>::Vector3()
{
}

template <typename T>
Vector3<T>::Vector3(T x, T y, T z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

template <typename T>
Vector3<T>::Vector3(const Vector2<T>& vector2, T z)
{
    this->x = vector2.x;
    this->y = vector2.y;
    this->z = z;
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
void
Vector3<T>::normalize()
{
    T norm = this->getNorm();

    x /= norm;
    y /= norm;
    z /= norm;
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
template <typename U>
Vector3<T>::operator	Vector3<U>() const
{
    return Vector3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z));
}
