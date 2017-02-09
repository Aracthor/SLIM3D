#include "slim/debug/assert.hpp"
#include "slim/maths/Helper.hpp"

namespace slim
{
namespace maths
{

template <typename T>
Matrix4x4<T>::Matrix4x4()
{
}

template <typename T>
Matrix4x4<T>::Matrix4x4(T n)
{
    this->setAllElements(n);
}

template <typename T>
Matrix4x4<T>::Matrix4x4(const Matrix4x4& copy)
{
    *this = copy;
}

template <typename T>
Matrix4x4<T>::~Matrix4x4()
{
}


template <typename T>
const T*
Matrix4x4<T>::asArray() const
{
    return reinterpret_cast<const T*>(this);
}

template <typename T>
bool
Matrix4x4<T>::isIdentity() const
{
    return (m_rows[0][0] == 1.0 && m_rows[0][1] == 0.0 && m_rows[0][2] == 0.0 && m_rows[0][3] == 0.0 &&
	    m_rows[1][0] == 0.0 && m_rows[1][1] == 1.0 && m_rows[1][2] == 0.0 && m_rows[1][3] == 0.0 &&
	    m_rows[2][0] == 0.0 && m_rows[2][1] == 0.0 && m_rows[2][2] == 1.0 && m_rows[2][3] == 0.0 &&
	    m_rows[3][0] == 0.0 && m_rows[3][1] == 0.0 && m_rows[3][2] == 0.0 && m_rows[3][3] == 1.0);
}


template <typename T>
void
Matrix4x4<T>::setIdentity()
{
    m_rows[0][0] = 1.0; m_rows[0][1] = 0.0; m_rows[0][2] = 0.0; m_rows[0][3] = 0.0;
    m_rows[1][0] = 0.0; m_rows[1][1] = 1.0; m_rows[1][2] = 0.0; m_rows[1][3] = 0.0;
    m_rows[2][0] = 0.0; m_rows[2][1] = 0.0; m_rows[2][2] = 1.0; m_rows[2][3] = 0.0;
    m_rows[3][0] = 0.0; m_rows[3][1] = 0.0; m_rows[3][2] = 0.0; m_rows[3][3] = 1.0;
}

template <typename T>
void
Matrix4x4<T>::setAllElements(T n)
{
    m_rows[0].setAllElements(n);
    m_rows[1].setAllElements(n);
    m_rows[2].setAllElements(n);
    m_rows[3].setAllElements(n);
}

template <typename T>
inline static void swap(T& a, T& b, T& tmp)
{
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void
Matrix4x4<T>::transpose()
{
    T	tmp;

    swap(m_rows[0][1], m_rows[1][0], tmp);
    swap(m_rows[0][2], m_rows[2][0], tmp);
    swap(m_rows[0][3], m_rows[3][0], tmp);
    swap(m_rows[1][2], m_rows[2][1], tmp);
    swap(m_rows[1][3], m_rows[3][1], tmp);
    swap(m_rows[2][3], m_rows[3][2], tmp);
}


template <typename T>
void
Matrix4x4<T>::translate(const Vector3<T>& vector)
{
    m_rows[3] = (m_rows[0] * vector[0] +
		 m_rows[1] * vector[1] +
		 m_rows[2] * vector[2] +
		 m_rows[3]);
}

template <typename T>
void
Matrix4x4<T>::rotateX(T angle)
{
    T	cosinus = SLIM_MATHS_COS(angle);
    T	sinus = SLIM_MATHS_SIN(angle);
    T	copy10 = m_rows[1][0],
	copy11 = m_rows[1][1],
	copy12 = m_rows[1][2],
	copy13 = m_rows[1][3],
	copy20 = m_rows[2][0],
	copy21 = m_rows[2][1],
	copy22 = m_rows[2][2],
	copy23 = m_rows[2][3];

    m_rows[1][0] = copy10 * cosinus + copy20 * sinus;
    m_rows[1][1] = copy11 * cosinus + copy21 * sinus;
    m_rows[1][2] = copy12 * cosinus + copy22 * sinus;
    m_rows[1][3] = copy13 * cosinus + copy23 * sinus;
    m_rows[2][0] = copy20 * cosinus - copy10 * sinus;
    m_rows[2][1] = copy21 * cosinus - copy11 * sinus;
    m_rows[2][2] = copy22 * cosinus - copy12 * sinus;
    m_rows[2][3] = copy23 * cosinus - copy13 * sinus;
}

template <typename T>
void
Matrix4x4<T>::rotateY(T angle)
{
    T	cosinus = SLIM_MATHS_COS(angle);
    T	sinus = SLIM_MATHS_SIN(angle);
    T	copy00 = m_rows[0][0],
	copy01 = m_rows[0][1],
	copy02 = m_rows[0][2],
	copy03 = m_rows[0][3],
	copy20 = m_rows[2][0],
	copy21 = m_rows[2][1],
	copy22 = m_rows[2][2],
	copy23 = m_rows[2][3];

    m_rows[0][0] = copy00 * cosinus - copy20 * sinus;
    m_rows[0][1] = copy01 * cosinus - copy21 * sinus;
    m_rows[0][2] = copy02 * cosinus - copy22 * sinus;
    m_rows[0][3] = copy03 * cosinus - copy23 * sinus;
    m_rows[2][0] = copy20 * cosinus + copy00 * sinus;
    m_rows[2][1] = copy21 * cosinus + copy01 * sinus;
    m_rows[2][2] = copy22 * cosinus + copy02 * sinus;
    m_rows[2][3] = copy23 * cosinus + copy03 * sinus;
}

template <typename T>
void
Matrix4x4<T>::rotateZ(T angle)
{
    T	cosinus = SLIM_MATHS_COS(angle);
    T	sinus = SLIM_MATHS_SIN(angle);
    T	copy00 = m_rows[0][0];
    T	copy01 = m_rows[0][1];
    T	copy02 = m_rows[0][2];
    T	copy03 = m_rows[0][3];
    T	copy10 = m_rows[1][0];
    T	copy11 = m_rows[1][1];
    T	copy12 = m_rows[1][2];
    T	copy13 = m_rows[1][3];

    m_rows[0][0] = copy00 * cosinus + copy10 * sinus;
    m_rows[0][1] = copy01 * cosinus + copy11 * sinus;
    m_rows[0][2] = copy02 * cosinus + copy12 * sinus;
    m_rows[0][3] = copy03 * cosinus + copy13 * sinus;
    m_rows[1][0] = copy10 * cosinus - copy00 * sinus;
    m_rows[1][1] = copy11 * cosinus - copy01 * sinus;
    m_rows[1][2] = copy12 * cosinus - copy02 * sinus;
    m_rows[1][3] = copy13 * cosinus - copy03 * sinus;
}

template <typename T>
void
Matrix4x4<T>::scale(const Vector3<T>& vector)
{
    m_rows[0].scale(vector.x);
    m_rows[1].scale(vector.y);
    m_rows[2].scale(vector.z);
}


template <typename T>
void
Matrix4x4<T>::orthogonal(T left, T right, T bottom, T top, T minView, T maxView)
{
    T	horizontalDifference = right - left;
    T	verticalDifference = top - bottom;
    T	depthDifference = maxView - minView;

    m_rows[0][0] = 2.0 / horizontalDifference;
    m_rows[0][1] = 0.0;
    m_rows[0][2] = 0.0;
    m_rows[0][3] = -((right + left) / horizontalDifference);
    m_rows[1][0] = 0.0;
    m_rows[1][1] = 2 / verticalDifference;
    m_rows[1][2] = 0.0;
    m_rows[1][3] = -((top + bottom) / verticalDifference);
    m_rows[2][0] = 0.0;
    m_rows[2][1] = 0.0;
    m_rows[2][2] = 2 / depthDifference;
    m_rows[2][3] = -((maxView + minView) / depthDifference);
    m_rows[3][0] = 0.0;
    m_rows[3][1] = 0.0;
    m_rows[3][2] = 0.0;
    m_rows[3][3] = 1.0;
}


template <typename T>
void
Matrix4x4<T>::perspective(T angle, T aspectRatio, T minView, T maxView)
{
    T	f = 1.0 / SLIM_MATHS_TAN(angle / 2.0);
    T	nf = 1.0 / (minView - maxView);
    T	mm = minView + maxView;

    m_rows[0][0] = f / aspectRatio;
    m_rows[0][1] = 0.0;
    m_rows[0][2] = 0.0;
    m_rows[0][3] = 0.0;
    m_rows[1][0] = 0.0;
    m_rows[1][1] = f;
    m_rows[1][2] = 0.0;
    m_rows[1][3] = 0.0;
    m_rows[2][0] = 0.0;
    m_rows[2][1] = 0.0;
    m_rows[2][2] = mm * nf;
    m_rows[2][3] = -1.0;
    m_rows[3][0] = 0.0;
    m_rows[3][1] = 0.0;
    m_rows[3][2] = (2.0 * mm) * nf;
    m_rows[3][3] = 0.0;
}

template <typename T>
void
Matrix4x4<T>::lookAt(const Vector3<T>& position, const Vector3<T>& target, const Vector3<T>& up)
{
    Vector3<T>	f(target - position);
    Vector3<T>	u(up);
    f.normalize();
    u.normalize();
    Vector3<T>	s(f * u);
    s.normalize();
    u = s * f;

    m_rows[0][0] = s.x;
    m_rows[1][0] = s.y;
    m_rows[2][0] = s.z;
    m_rows[3][0] = 0.0f;
    m_rows[0][1] = u.x;
    m_rows[1][1] = u.y;
    m_rows[2][1] = u.z;
    m_rows[3][1] = 0.0f;
    m_rows[0][2] = -f.x;
    m_rows[1][2] = -f.y;
    m_rows[2][2] = -f.z;
    m_rows[3][2] = 0.0f;
    m_rows[3][0] = -s.getDotProduct(position);
    m_rows[3][1] = -u.getDotProduct(position);
    m_rows[3][2] = f.getDotProduct(position);
    m_rows[3][3] = 1.0f;
}


template <typename T>
Vector4<T>&
Matrix4x4<T>::operator[](unsigned int index)
{
    return m_rows[index];
}

template <typename T>
const Vector4<T>&
Matrix4x4<T>::operator[](unsigned int index) const
{
    return m_rows[index];
}

}
}

#ifdef _DEBUG
template <typename T>
std::ostream&
operator<<(std::ostream& stream, const slim::maths::Matrix4x4<T>& matrix)
{
    stream << matrix[0] << std::endl
	   << matrix[1] << std::endl
	   << matrix[2] << std::endl
	   << matrix[3] << std::endl;
    return stream;
}
#endif // _DEBUG
