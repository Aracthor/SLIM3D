namespace slim
{
namespace maths
{

template <typename T>
Helper<T>
Helper<T>::instance;


template <typename T>
Helper<T>::Helper()
{
}

template <typename T>
Helper<T>::~Helper()
{
}


template <typename T>
void
Helper<T>::onInit()
{
    T	angle;

    for (unsigned int i = 0; i < SLIM_MATHS_HELPER_PRECALC_NUMBER; i++)
    {
	angle = SLIM_MATHS_PI * 2 * static_cast<float>(i) / static_cast<float>(SLIM_MATHS_HELPER_PRECALC_NUMBER);
	m_coses[i] = lib::cos(angle);
	m_sines[i] = lib::sin(angle);
	m_tanes[i] = lib::tan(angle);
    }
}

template <typename T>
void
Helper<T>::onDestroy()
{
}


template <typename T>
T
Helper<T>::getCosinus(T angle) const
{
    return (m_coses[this->getAroundAngle(angle)]);
}

template <typename T>
T
Helper<T>::getSinus(T angle) const
{
    return (m_sines[this->getAroundAngle(angle)]);
}

template <typename T>
T
Helper<T>::getTangeante(T angle) const
{
    return (m_tanes[this->getAroundAngle(angle)]);
}


template <typename T>
T
Helper<T>::getAroundAngle(T angle) const
{
    ASSERT(angle >= 0.0 && angle < SLIM_MATHS_PI * 2);
    return (static_cast<T>((static_cast<unsigned int>(SLIM_MATHS_HELPER_PRECALC_NUMBER) * angle) / SLIM_MATHS_HELPER_PRECALC_NUMBER));
}

}
}
