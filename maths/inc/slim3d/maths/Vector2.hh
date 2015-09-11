//
// Vector2.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Fri Sep  4 23:59:15 2015 Aracthor
// Last Update Fri Sep 11 11:24:40 2015 Aracthor
//

#ifndef SLIM3D_MATHS_VECTOR2_HH_
# define SLIM3D_MATHS_VECTOR2_HH_

namespace slim
{
namespace maths
{

template <typename T>
class	Vector2
{
public:
    inline Vector2();
    inline Vector2(T x, T y);
    inline Vector2(const Vector2<T>& vector);
    inline ~Vector2();

public:
    T	x;
    T	y;

public:
    inline bool	equals(const Vector2<T>& vector) const;
    inline T	getNorm() const;
    inline T	getSquaredNorm() const;
    inline T	getDotProduct(const Vector2<T>& vector) const;

public:
    void	setAllElements(T n);
    void	normalize();

public:
    Vector2<T>&	addTo(const Vector2<T>& vector);
    Vector2<T>&	subTo(const Vector2<T>& vector);
    Vector2<T>&	scaleTo(T n);
    Vector2<T>&	unscaleTo(T n);
    Vector2<T>&	lerpInterpolation(const Vector2<T>& vector, T ratio);

public:
    inline Vector2<T>	add(const Vector2<T>& vector) const;
    inline Vector2<T>	sub(const Vector2<T>& vector) const;
    inline Vector2<T>	scale(T n) const;
    inline Vector2<T>	unscale(T n) const;

public:
    inline Vector2<T>	operator-() const;

public:
    // Operators similar to methods
    inline Vector2<T>&	operator+=(const Vector2<T>& vector);
    inline Vector2<T>&	operator-=(const Vector2<T>& vector);
    inline Vector2<T>&	operator*=(T n);
    inline Vector2<T>&	operator/=(T n);
    inline Vector2<T>	operator+(const Vector2<T>& vector) const;
    inline Vector2<T>	operator-(const Vector2<T>& vector) const;
    inline Vector2<T>	operator*(T n) const;
    inline Vector2<T>	operator/(T n) const;
    inline bool		operator==(const Vector2<T>& vector) const;
    inline bool		operator!=(const Vector2<T>& vector) const;

public:
    inline T		operator[](unsigned int index) const;
    inline T&		operator[](unsigned int index);

public:
    template <typename U>
    inline operator	Vector2<U>() const;
};

typedef Vector2<float>		Vector2f;
typedef Vector2<double>		Vector2d;
typedef Vector2<long double>	Vector2ld;
typedef Vector2<int>		Vector2i;
typedef Vector2<long>		Vector2l;

}

typedef maths::Vector2f	        Vector2;

}

# include "Vector2.hpp"

#endif // !SLIM3D_MATHS_VECTOR2_HH_
