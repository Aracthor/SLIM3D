//
// Matrix4x4.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Sat Sep  5 20:12:06 2015 Aracthor
// Last Update Sun Sep  6 00:03:30 2015 Aracthor
//

template <typename T>
Matrix4x4<T>::Matrix4x4()
{
    this->setIdentity();
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
void
Matrix4x4<T>::setIdentity()
{
    m_rows[0][0] = 1; m_rows[0][1] = 0; m_rows[0][2] = 0; m_rows[0][3] = 0;
    m_rows[1][0] = 0; m_rows[1][1] = 1; m_rows[1][2] = 0; m_rows[1][3] = 0;
    m_rows[2][0] = 0; m_rows[2][1] = 0; m_rows[2][2] = 1; m_rows[2][3] = 0;
    m_rows[3][0] = 0; m_rows[3][1] = 0; m_rows[3][2] = 0; m_rows[3][3] = 1;
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
void
Matrix4x4<T>::translate(const Vector3<T>& vector)
{
    m_rows[3] = (m_rows[0] * vector[0] +
		 m_rows[1] * vector[1] +
		 m_rows[2] * vector[2] +
		 m_rows[3]);
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
