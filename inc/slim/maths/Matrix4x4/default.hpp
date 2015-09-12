//
// default.hpp for SLIM in /home/aracthor/programs/projects/SLIM/maths
// 
// Made by Aracthor
// 
// Started on  Sun Sep  6 00:04:44 2015 Aracthor
// Last Update Sun Sep  6 00:29:24 2015 Aracthor
//

namespace slim
{
namespace maths
{

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

}
}
