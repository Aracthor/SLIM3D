#ifndef SLIM_MATHS_QUATERNION_HPP_
# define SLIM_MATHS_QUATERNION_HPP_

# include "slim/maths/Vector3.hpp"
# include "slim/maths/Matrix4x4.hpp"

namespace slim
{
namespace maths
{

template <typename T>
class	Quaternion
{
public:
    inline Quaternion();
    inline Quaternion(const Vector3<T>& vector, T scalar = 0.0);
    inline Quaternion(const Vector4<T>& vector);
    inline Quaternion(const Quaternion<T>& reference);
    inline ~Quaternion();

public:
    inline void		normalize();
    inline void		conjugate();
    inline void		invert();
    inline void		lerpInterpolation(const Quaternion<T>& quaternion, T ratio);
    void		slerpInterpolation(const Quaternion<T>& quaternion, T ratio);
    Quaternion<T>&	productTo(const Quaternion<T>& quaternion);

public:
    Quaternion<T>	product(const Quaternion<T>& quaternion) const;

public:
    inline T	getNorm() const; // Should be useless as long as they are all normalized (norm == 1).
    bool	isNormalized() const;
    void	rotate(Vector3<T>& vector) const;
    void	toMatrix(Matrix4x4<T>& matrix) const;

public:
    inline const Vector4<T>&	asVector() const;
    inline Vector4<T>&		asVector();

public:
    inline const Vector3<T>&	getVector() const;
    inline T			getScalar() const;

public:
    inline Quaternion<T>&	operator*=(const Quaternion<T>& quaternion);
    inline Quaternion<T>	operator*(const Quaternion<T>& quaternion) const;

public:
    inline T	operator[](unsigned int index) const;
    inline T&	operator[](unsigned int index);

private:
    Vector3<T>	m_vector;
    T		m_scalar;
};

}
}

# include "Quaternion.hpp"

#endif // !SLIM_MATHS_QUATERNION_HPP_
