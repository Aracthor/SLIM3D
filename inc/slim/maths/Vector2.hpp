#ifndef SLIM_MATHS_VECTOR2_HPP_
# define SLIM_MATHS_VECTOR2_HPP_

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
    Vector2<T>&		operator=(const Vector2<T>& vector);

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
typedef Vector2<unsigned int>	Vector2ui;
typedef Vector2<long>		Vector2l;
typedef Vector2<unsigned long>	Vector2ul;

}

typedef maths::Vector2f	        Vector2;

}

# ifdef _DEBUG
# include <ostream>
template <typename T>
inline std::ostream&	operator<<(std::ostream& stream, const slim::maths::Vector2<T>& vector);
# endif // _DEBUG

# include "Vector2.ipp"

#endif // !SLIM_MATHS_VECTOR2_HPP_
