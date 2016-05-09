#include "slim/debug/assert.hpp"

#include "slim/string.h"

namespace slim
{
namespace containers
{

template <typename T, std::size_t N>
PresizedPool<T, N>::PresizedPool()
{
    memset(m_busy, 0, sizeof(m_busy));
}

template <typename T, std::size_t N>
PresizedPool<T, N>::~PresizedPool()
{
    this->clear();
}


template <typename T, std::size_t N>
void
PresizedPool<T, N>::clear()
{
    std::size_t	i;

    for (i = 0; i < N; i++)
    {
	if (m_busy[i])
	{
	    reinterpret_cast<T*>(m_data)[i].~T();
	    m_busy[i] = false;
	}
    }
}

template <typename T, std::size_t N>
template <typename ...Args>
T*
PresizedPool<T, N>::create(Args&& ...args)
{
    std::size_t	i = 0;
    T*		elem;

    while (m_busy[i] == true)
    {
	i++;
	SLIM_DEBUG_ASSERT(i < N);
    }

    m_busy[i] = true;
    elem = &reinterpret_cast<T*>(m_data)[i];
    new (elem) T(args...);
    return elem;
}

template <typename T, std::size_t N>
void
PresizedPool<T, N>::destroy(T& elem)
{
    std::size_t	position = (static_cast<std::size_t>(reinterpret_cast<const byte*>(&elem) - m_data)) / sizeof(T) * sizeof(bool);

    SLIM_DEBUG_ASSERT(m_busy[position] == true);
    m_busy[position] = false;
    elem.~T();
}

}
}
