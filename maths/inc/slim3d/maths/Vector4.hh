//
// Vector4.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Fri Sep  4 23:59:15 2015 Aracthor
// Last Update Sat Sep  5 16:25:22 2015 Aracthor
//

#ifndef SLIM3D_MATHS_VECTOR4_HH_
# define SLIM3D_MATHS_VECTOR4_HH_

# include "slim3d/maths/lib.hh"
# include "slim3d/maths/Vector2.hh"

namespace slim
{
namespace maths
{

template <typename T>
class	Vector4
{
public:
    Vector4();
    Vector4(T x, T y, T z, T w);
    Vector4(const Vector2<T>& vector2, T z, T w);
    Vector4(const Vector3<T>& vector3, T w);
    Vector4(const Vector4<T>& vector);
    ~Vector4();

public:
    T	x;
    T	y;
    T	z;
    T	w;

public:
    inline bool	equals(const Vector4<T>& vector) const;
    inline T	getNorm() const;
    inline T	getSquaredNorm() const;

public:
    void	normalize();

public:
    Vector4<T>&	addTo(const Vector4<T>& vector);
    Vector4<T>&	subTo(const Vector4<T>& vector);
    Vector4<T>&	scaleTo(T n);
    Vector4<T>&	unscaleTo(T n);

public:
    inline Vector4<T>	add(const Vector4<T>& vector) const;
    inline Vector4<T>	sub(const Vector4<T>& vector) const;
    inline Vector4<T>	scale(T n) const;
    inline Vector4<T>	unscale(T n) const;

public:
    inline Vector4<T>	operator-() const;

public:
    // Operators similar to methods
    inline Vector4<T>&	operator+=(const Vector4<T>& vector);
    inline Vector4<T>&	operator-=(const Vector4<T>& vector);
    inline Vector4<T>&	operator*=(T n);
    inline Vector4<T>&	operator/=(T n);
    inline Vector4<T>	operator+(const Vector4<T>& vector) const;
    inline Vector4<T>	operator-(const Vector4<T>& vector) const;
    inline Vector4<T>	operator*(T n) const;
    inline Vector4<T>	operator/(T n) const;
    inline bool		operator==(const Vector4<T>& vector) const;
    inline bool		operator!=(const Vector4<T>& vector) const;

public:
    inline T		operator[](unsigned int index) const;
    inline T&		operator[](unsigned int index);

public:
    template <typename U>
    operator	Vector4<U>() const;
};

# include "Vector4.hpp"

typedef Vector4<float>		Vector4f;
typedef Vector4<double>		Vector4d;
typedef Vector4<long double>	Vector4ld;
typedef Vector4<int>		Vector4i;
typedef Vector4<long>		Vector4l;

}

typedef maths::Vector4f	        Vector4;

}

#endif // !SLIM3D_MATHS_VECTOR4_HH_
