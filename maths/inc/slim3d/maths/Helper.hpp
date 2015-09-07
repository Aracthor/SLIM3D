//
// Helper.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Fri Sep  4 19:46:34 2015 Aracthor
// Last Update Sat Sep  5 12:49:41 2015 Aracthor
//

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
Helper<T>::init()
{
    T	angle;

    for (unsigned int i = 0; i < SLIM3D_MATHS_HELPER_PRECALC_NUMBER; i++)
    {
	angle = SLIM3D_MATHS_PI * 2 * static_cast<float>(i) / static_cast<float>(SLIM3D_MATHS_HELPER_PRECALC_NUMBER);
	m_coses[i] = lib::cos(angle);
	m_sines[i] = lib::sin(angle);
	m_tanes[i] = lib::tan(angle);
    }
}

template <typename T>
void
Helper<T>::destroy()
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


T
Helper<T>::getAroundAngle(T angle) const
{
    ASSERT();
    return (static_cast<T>((static_cast<unsigned int>(SLIM3D_MATHS_HELPER_PRECALC_NUMBER) * angle) / SLIM3D_MATHS_HELPER_PRECALC_NUMBER));
}