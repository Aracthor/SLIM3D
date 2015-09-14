#ifndef SLIM_MATHS_VECTOR4_HH_
# define SLIM_MATHS_VECTOR4_HH_

# include "slim/maths/Vector2.hh"
# include "slim/maths/Vector3.hh"

# if __SSE__ == 1
#  include <xmmintrin.h>
# endif

namespace slim
{
namespace maths
{

template <typename T>
class	Quaternion;

template <typename T>
class	Vector4
{
public:
    inline Vector4();
    inline Vector4(T x, T y, T z, T w);
    inline Vector4(const Vector2<T>& vector2, T z, T w);
    inline Vector4(const Vector3<T>& vector3, T w = 0);
    inline Vector4(const Vector4<T>& vector);
    inline ~Vector4();

public:
    T	x;
    T	y;
    T	z;
    T	w;

public:
    inline bool	equals(const Vector4<T>& vector) const;
    inline T	getNorm() const;
    inline T	getSquaredNorm() const;
    inline T	getDotProduct(const Vector4<T>& vector) const;

public:
    void	setAllElements(T n);
    void	normalize();
    void	set(const Vector2<T>& vector2, T z, T w);
    void	set(const Vector3<T>& vector3, T w);

public:
    Vector4<T>&	addTo(const Vector4<T>& vector);
    Vector4<T>&	subTo(const Vector4<T>& vector);
    Vector4<T>&	scaleTo(T n);
    Vector4<T>&	unscaleTo(T n);
    Vector4<T>&	lerpInterpolation(const Vector4<T>& vector, T ratio);

public:
    inline const Quaternion<T>&	asQuaternion() const;
    inline Quaternion<T>&	asQuaternion();

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
    inline operator	Quaternion<T>() const;
    template <typename U>
    inline operator	Vector4<U>() const;

#if __SSE__ == 1
    Vector4(__m128 data);

    Vector4<T>&	set(__m128 data);

    inline __m128	asSSE() const;

    inline Vector4<T>&	operator=(__m128 data);
#endif
};

typedef Vector4<float>		Vector4f;
typedef Vector4<double>		Vector4d;
typedef Vector4<long double>	Vector4ld;
typedef Vector4<int>		Vector4i;
typedef Vector4<long>		Vector4l;

}

typedef maths::Vector4f	        Vector4;

}

# include "Vector4.hpp"

# if __SSE__ == 1
#  include "Vector4/SSE.hpp"
# endif

#endif // !SLIM_MATHS_VECTOR4_HH_