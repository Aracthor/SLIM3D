#ifndef SLIM_MATHS_VECTOR3_HPP_
# define SLIM_MATHS_VECTOR3_HPP_

# include "slim/maths/Vector2.hpp"

namespace slim
{
namespace maths
{

template <typename T>
class	Vector3
{
public:
    inline Vector3();
    inline Vector3(T x, T y, T z);
    inline Vector3(const Vector2<T>& vector2, T z);
    inline Vector3(const Vector3<T>& vector);
    inline ~Vector3();

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
    void	set(T x, T y, T z);
    void        set(const Vector2<T>& vector2, T z);

public:
    Vector3<T>&	addTo(const Vector3<T>& vector);
    Vector3<T>&	subTo(const Vector3<T>& vector);
    Vector3<T>&	vectorProductTo(const Vector3<T>& vector);
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
    Vector3<T>&		operator=(const Vector3<T>& vector);

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
typedef Vector3<unsigned int>	Vector3ui;
typedef Vector3<long>		Vector3l;
typedef Vector3<unsigned long>	Vector3ul;

}

typedef maths::Vector3f	        Vector3;

}

# ifdef _DEBUG
# include <ostream>
template <typename T>
inline std::ostream&	operator<<(std::ostream& stream, const slim::maths::Vector3<T>& vector);
# endif // _DEBUG

# include "Vector3.ipp"

#endif // !SLIM_MATHS_VECTOR3_HPP_
