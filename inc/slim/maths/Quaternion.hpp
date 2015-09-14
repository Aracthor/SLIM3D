#include "slim/debug/SyscallException.hh"

namespace slim
{
namespace maths
{

template <typename T>
Quaternion<T>::Quaternion()
{
}

template <typename T>
Quaternion<T>::Quaternion(const Vector3<T>& vector, T scalar) :
    m_vector(vector),
    m_scalar(scalar)
{
}

template <typename T>
Quaternion<T>::Quaternion(const Vector4<T>& vector) :
    m_vector(vector.x, vector.y, vector.z),
    m_scalar(vector.w)
{
}

template <typename T>
Quaternion<T>::Quaternion(const Quarternion<T>& quaternion) :
    m_vector(quaternion.getVector()),
    m_scalar(quaternion.getScalar())
{
}

template <typename T>
Quaternion<T>::~Quaternion()
{
}


template <typename T>
void
Quaternion<T>::normalize()
{
    m_vector.normalize();
}

template <typename T>
void
Quaternion<T>::conjugate()
{
    m_vector.scaleTo(-1.0);
}

template <typename T>
void
Quaternion<T>::invert()
{
    SLIM_DEBUG_ASSERT(this->isNormalized());
    this->conjugate();
}

template <typename T>
void
Quaternion<T>::lerpInterpolation(const Quaternion<T>& quaternion, T ratio)
{
    this->asVector().lerpInterpolation(quaternion.asVector(), ratio);
}

template <typename T>
void
Quaternion<T>::slerpInterpolation(const Quaternion<T>& quaternion, T ratio)
{
    T	angle;
    T	sinus;
    T	wp, wq;

    angle = SLIM_MATHS_ACOS(this->asVector().dotProduct(quaternion.asVector()));
    sinus = SLIM_MATHS_SIN(angle);
    wp = (SLIM_MATHS_SIN(1 - ratio) * angle) / sinus;
    wq = (SLIM_MATHS_SIN(ratio) * angle) / sinus;

    this->asVector() *= wp;
    this->asVector() += quaternion.asVector() * wq;
}

template <typename T>
Quaternion<T>&
Quaternion<T>::productTo(const Quaternion<T>& quaternion)
{
    Vector3<T>	tmpVector = m_vector;
    T		tmpScalar = m_scalar;

    m_scalar = m_scalar * quaternion.getScalar() - m_vector.dotProduct(quaternion);

    m_vector *= quaternion.getVector();
    tmpVector *= quaternion.getScalar();
    m_vector += tmpVector;
    tmpVector = quaternion.getVector();
    tmpVector *= tmpScalar;
    m_vector += tmpVector;

    return *this;
}


template <typename T>
Quaternion<T>
Quaternion<T>::product(const Quaternion<T>& quaternion) const
{
    Quaternion<T>	product;
    Vector3<T>		tmpVector = m_vector;

    product.m_scalar = m_scalar * quaternion.getScalar() - m_vector.dotProduct(quaternion.asVector());

    product.m_vector = m_vector;
    product.m_vector *= quaternion.getVector();
    tmpVector *= quaternion.getScalar();
    product.m_vector += tmpVector;
    tmpVector = quaternion.getVector();
    tmpVector *= m_scalar;
    product.m_vector += tmpVector;

    return product;
}


template <typename T>
T
Quaternion<T>::getNorm() const
{
    return this->asVector().getNorm();
}

template <typename T>
bool
Quaternion<T>::isNormalized() const
{
    // As long as we use the unprecise lerp method, it might be slightly different.
    T difference = this->getNorm() - 1.0;
    return (difference < 0.00001 && difference > -0.00001);
}

template <typename T>
void
Quaternion<T>::rotate(Vector3<T>& vector) const
{
    Quaternion<T>	result;
    Quaternion<T>	tmp(*this);

    result.m_scalar = m_vector.dotProduct(quaternion.asVector());
    result.m_vector = m_vector;
    result.m_vector *= vector;
    tmp.invert();
    result *= tmp;
    vector = result.getVector();
}

template <typename T>
void
Quaternion<T>::toMatrix(Matrix4x4<T>& matrix) const
{
    const Vector4<T>&	vector = this->asVector();
    T	x2 = vector.x * vector.x;
    T	y2 = vector.y * vector.y;
    T	z2 = vector.z * vector.z;

    matrix[0][0] = 1.0 - 2.0 * y2 - 2.0 * z2;
    matrix[0][1] = 2.0 * vector.x * vector.y + 2.0 * vector.z * vector.w;
    matrix[0][2] = 2.0 * vector.x * vector.z - 2.0 * vector.y * vector.w;
    matrix[0][3] = 0.0;
    matrix[1][0] = 2.0 * vector.x * vector.y - 2.0 * vector.z * vector.w;
    matrix[1][1] = 1.0 - 2.0 * x2 - 2.0 * z2;
    matrix[1][2] = 2.0 * vector.y * vector.z + 2.0 * vector.x * vector.w;
    matrix[1][3] = 0.0;
    matrix[2][0] = 2.0 * vector.x * vector.z + 2.0 * vector.y * vector.w;
    matrix[2][1] = 2.0 * vector.y * vector.z - 2.0 * vector.x * vector.w;
    matrix[2][2] = 1.0 - 2.0 * x2 - 2.0 * y2;
    matrix[2][3] = 0.0;
    matrix[3][0] = 0.0;
    matrix[3][1] = 0.0;
    matrix[3][2] = 0.0;
    matrix[3][3] = 1.0;
}


template <typename T>
const Vector4<T>&
Quaternion<T>::asVector() const
{
    return *reinterpret_cast<const Vector4<T>*>(this);
}

template <typename T>
Vector4<T>&
Quaternion<T>::asVector()
{
    return *reinterpret_cast<Vector4<T>*>(this);
}


template <typename T>
const Vector3&
Quaternion<T>::getVector() const
{
    return m_vector;
}

template <typename T>
float
Quaternion<T>::getScalar() const
{
    return m_scalar;
}


template <typename T>
Quaternion<T>&
Quaternion<T>::operator*=(const Quaternion<T>& quaternion)
{
    return this->productTo(quaternion);
}

template <typename T>
Quaternion<T>
Quaternion<T>::operator*(const Quaternion<T>& quaternion) const
{
    return this->product(quaternion);
}


template <typename T>
T
Quaternion<T>::operator[](unsigned int index) const
{
    return this->asVector()[index];
}

template <typename T>
T&
Quaternion<T>::operator[](unsigned int index)
{
    return this->asVector()[index];
}

}
}
