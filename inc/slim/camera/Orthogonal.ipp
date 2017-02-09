namespace slim
{
namespace camera
{

float
Orthogonal::getLeft() const
{
    return m_left;
}

float
Orthogonal::getRight() const
{
    return m_right;
}

float
Orthogonal::getBottom() const
{
    return m_bottom;
}

float
Orthogonal::getTop() const
{
    return m_top;
}

float
Orthogonal::getRangeMin() const
{
    return m_rangeMin;
}

float
Orthogonal::getRangeMax() const
{
    return m_rangeMax;
}


void
Orthogonal::setLeft(float left)
{
    m_left = left;
}

void
Orthogonal::setRight(float right)
{
    m_right = right;
}

void
Orthogonal::setBottom(float bottom)
{
    m_bottom = bottom;
}

void
Orthogonal::setTop(float top)
{
    m_top = top;
}

void
Orthogonal::setRangeMin(float rangeMin)
{
    m_rangeMin = rangeMin;
}

void
Orthogonal::setRangeMax(float rangeMax)
{
    m_rangeMax = rangeMax;
}


void
Orthogonal::getProjectionMatrix(Matrix4x4& matrix) const
{
    matrix.orthogonal(m_left, m_right, m_bottom, m_top, m_rangeMin, m_rangeMax);
}

}
}
