//
// SSE.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Sun Sep  6 00:02:44 2015 Aracthor
// Last Update Sun Sep  6 00:04:48 2015 Aracthor
//

# include <xmmintrin.h>

namespace slim
{
namespace maths
{

template <typename T>
void
Matrix4x4<T>::transpose()
{
    __m128 row0 = m_rows[0].asSSE();
    __m128 row1 = m_rows[1].asSSE();
    __m128 row2 = m_rows[2].asSSE();
    __m128 row3 = m_rows[3].asSSE();
    _MM_TRANSPOSE4_PS(row0, row1, row2, row3);
    m_rows[0] = row0;
    m_rows[1] = row1;
    m_rows[2] = row2;
    m_rows[3] = row3;
}

}
}
