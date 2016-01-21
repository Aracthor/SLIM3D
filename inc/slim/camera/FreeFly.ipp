namespace slim
{
namespace camera
{

float
FreeFly::getInertia() const
{
    return m_inertia;
}

float
FreeFly::getSpeed() const
{
    return m_speed;
}

float
FreeFly::getSensitivity() const
{
    return m_sensitivity;
}


void
FreeFly::advance(float speed)
{
    m_move += m_forward * speed;
}

}
}
