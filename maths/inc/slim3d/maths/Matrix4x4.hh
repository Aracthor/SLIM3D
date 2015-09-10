//
// Matrix4x4.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Sat Sep  5 20:12:09 2015 Aracthor
// Last Update Wed Sep  9 14:00:28 2015 Aracthor
//

#ifndef SLIM3D_MATHS_MATRIX4X4_HH_
# define SLIM3D_MATHS_MATRIX4X4_HH_

# include "slim3d/maths/Vector4.hh"

namespace slim
{
namespace maths
{

template <typename T>
class	Matrix4x4
{
public:
    Matrix4x4();
    explicit Matrix4x4(T n);
    Matrix4x4(const Matrix4x4& copy);

public:
    const T*	asArray() const;
    inline bool	isIdentity() const;

public:
    void	setIdentity();
    void	setAllElements(T n);
    void	transpose();

public:
    inline void	translate(const Vector3<T>& vector);
    void	rotateX(T angle);
    void	rotateY(T angle);
    void	rotateZ(T angle);
    void	scale(const Vector3<T>& vector);

public:
    void	perspective(T angle, T aspectRatio, T minView, T maxView);
    void	lookAt(const Vector3<T>& position, const Vector3<T>& target, const Vector3<T>& up);

public:
    inline Vector4<T>&		operator[](unsigned int index);
    inline const Vector4<T>&	operator[](unsigned int index) const;

private:
    Vector4<T>	m_rows[4];
};

typedef	Matrix4x4<float>	Matrix4x4f;
typedef	Matrix4x4<double>	Matrix4x4d;
typedef	Matrix4x4<long double>	Matrix4x4ld;
typedef	Matrix4x4<int>		Matrix4x4i;
typedef	Matrix4x4<long>		Matrix4x4l;

}

typedef maths::Matrix4x4f		Matrix4x4;

}

# include "Matrix4x4.hpp"

# if __SSE__ == 1
#  include "Matrix4x4/SSE.hpp"
# else
#  include "Matrix4x4/default.hpp"
# endif

#endif // !SLIM3D_MATHS_MATRIX4X4_HH_
