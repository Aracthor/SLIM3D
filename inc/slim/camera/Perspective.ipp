namespace slim
{
namespace camera
{

float
Perspective::getFOV() const
{
    return m_fov;
}

float
Perspective::getAspectRatio() const
{
    return m_aspectRatio;
}

float
Perspective::getRangeMin() const
{
    return m_rangeMin;
}

float
Perspective::getRangeMax() const
{
    return m_rangeMax;
}


void
Perspective::setFOV(float fov)
{
    m_fov = fov;
}

void
Perspective::setAspectRatio(float screenWidth, float screenHeight)
{
    m_aspectRatio = screenWidth / screenHeight;
}

void
Perspective::setRangeMin(float rangeMin)
{
    m_rangeMin = rangeMin;
}

void
Perspective::setRangeMax(float rangeMax)
{
    m_rangeMax = rangeMax;
}


void
Perspective::getProjectionMatrix(Matrix4x4& matrix) const
{
    matrix.perspective(m_fov, m_aspectRatio, m_rangeMin, m_rangeMax);
}

}
}
