//
// Quaternion.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Thu Sep 10 18:30:30 2015 Aracthor
// Last Update Thu Sep 10 22:10:25 2015 Aracthor
//

#ifndef SLIM3D_MATHS_QUATERNION_HH_
# define SLIM3D_MATHS_QUATERNION_HH_

# include "slim3d/maths/Vector3.hh"
# include "slim3d/maths/Matrix4x4.hh"

namespace slim
{
namespace maths
{

template <typename T>
class	Quaternion
{
public:
    Quaternion();
    Quaternion(const Vector3<T>& vector, T scalar = 0.0);
    Quaternion(const Vector4<T>& vector);
    Quaternion(const Quaternion<T>& reference);
    ~Quaternion();

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

private:
    Vector3<T>	m_vector;
    float	m_scalar;
};

}
}

# include "Quaternion.hpp"

#endif // !SLIM3D_MATHS_QUATERNION_HH_
