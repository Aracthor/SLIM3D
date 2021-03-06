namespace slim
{
namespace maths
{

template <>
void
Matrix4x4<float>::transpose()
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
