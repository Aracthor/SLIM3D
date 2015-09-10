//
// Vector3.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Fri Sep  4 23:59:15 2015 Aracthor
// Last Update Thu Sep 10 21:22:26 2015 Aracthor
//

#ifndef SLIM3D_MATHS_VECTOR3_HH_
# define SLIM3D_MATHS_VECTOR3_HH_

# include "slim3d/maths/Vector2.hh"

namespace slim
{
namespace maths
{

template <typename T>
class	Vector3
{
public:
    Vector3();
    Vector3(T x, T y, T z);
    Vector3(const Vector2<T>& vector2, T z);
    Vector3(const Vector3<T>& vector);
    ~Vector3();

public:
    T	x;
    T	y;
    T	z;

public:
    inline bool	equals(const Vector3<T>& vector) const;
    inline T	getNorm() const;
    inline T	getSquaredNorm() const;
    inline T	getDotProduct(const Vector3<T>& vector) const;

public:
    void	setAllElements(T n);
    void	normalize();
    void        set(const Vector2<T>& vector2, T z);

public:
    Vector3<T>&	addTo(const Vector3<T>& vector);
    Vector3<T>&	subTo(const Vector3<T>& vector);
    Vector3<T>&	crossProductTo(const Vector3<T>& vector);
    Vector3<T>&	scaleTo(T n);
    Vector3<T>&	unscaleTo(T n);
    Vector3<T>&	lerpInterpolation(const Vector3<T>& vector, T ratio);

public:
    inline Vector3<T>	add(const Vector3<T>& vector) const;
    inline Vector3<T>	sub(const Vector3<T>& vector) const;
    inline Vector3<T>	vectorProduct(const Vector3<T>& vector) const;
    inline Vector3<T>	scale(T n) const;
    inline Vector3<T>	unscale(T n) const;

public:
    inline Vector3<T>	operator-() const;

public:
    // Operators similar to methods
    inline Vector3<T>&	operator+=(const Vector3<T>& vector);
    inline Vector3<T>&	operator-=(const Vector3<T>& vector);
    inline Vector3<T>&	operator*=(const Vector3<T>& vector);
    inline Vector3<T>&	operator*=(T n);
    inline Vector3<T>&	operator/=(T n);
    inline Vector3<T>	operator+(const Vector3<T>& vector) const;
    inline Vector3<T>	operator-(const Vector3<T>& vector) const;
    inline Vector3<T>	operator*(const Vector3<T>& vector) const;
    inline Vector3<T>	operator*(T n) const;
    inline Vector3<T>	operator/(T n) const;
    inline bool		operator==(const Vector3<T>& vector) const;
    inline bool		operator!=(const Vector3<T>& vector) const;

public:
    inline T		operator[](unsigned int index) const;
    inline T&		operator[](unsigned int index);

public:
    template <typename U>
    inline operator	Vector3<U>() const;
};

typedef Vector3<float>		Vector3f;
typedef Vector3<double>		Vector3d;
typedef Vector3<long double>	Vector3ld;
typedef Vector3<int>		Vector3i;
typedef Vector3<long>		Vector3l;

}

typedef maths::Vector3f	        Vector3;

}

# include "Vector3.hpp"

#endif // !SLIM3D_MATHS_VECTOR3_HH_
