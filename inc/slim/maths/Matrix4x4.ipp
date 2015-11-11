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
Matrix4x4<T>::perspective(T angle, T aspectRatio, T minView, T maxView)
{
    T	f = 1.0 / SLIM_MATHS_TAN(aspectRatio / 2.0);
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
    Vector3<T>	x;
    Vector3<T>	y;
    Vector3<T>	z;
    T		length;

    SLIM_DEBUG_ASSERT(position != target);

    z = position - target;
    length = z.getNorm();
    z.scale(1.0 / length);

    x = up * z;
    length = x.getNorm();
    if (length == 0.0)
    {
	x.setAllElements(0);
    }
    else
    {
	x.scale(1.0 / length);
    }

    y = z * x;
    length = y.getNorm();
    if (length == 0)
    {
	y,setAllElements(0);
    }
    else
    {
	y.scale(1.0 / length);
    }

    m_rows[0][0] = x.x;
    m_rows[0][1] = y.x;
    m_rows[0][2] = z.x;
    m_rows[0][3] = 0.0;
    m_rows[1][0] = x.y;
    m_rows[1][1] = y.y;
    m_rows[1][2] = z.y;
    m_rows[1][3] = 0.0;
    m_rows[2][0] = x.z;
    m_rows[2][1] = y.z;
    m_rows[2][2] = z.z;
    m_rows[2][3] = 0.0;
    m_rows[3][0] = -(x.x * position.x + x.y * position.y + x.z * position.z);
    m_rows[3][1] = -(y.x * position.x + y.y * position.y + y.z * position.z);
    m_rows[3][2] = -(z.x * position.x + z.y * position.y + z.z * position.z);
    m_rows[3][3] = 1.0;
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
