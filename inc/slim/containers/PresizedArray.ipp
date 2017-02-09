#include <typeinfo>

#include "slim/string.h"
#include "slim/debug/assert.hpp"
#include "slim/debug/exit.hpp"

namespace slim
{
namespace containers
{

template <typename T, std::size_t N>
PresizedArray<T, N>::PresizedArray()
{
    m_currentSize = 0;
}

template <typename T, std::size_t N>
PresizedArray<T, N>::PresizedArray(T defaultData)
{
    this->fill(defaultData);
}

template <typename T, std::size_t N>
PresizedArray<T, N>::~PresizedArray()
{
}


template <typename T, std::size_t N>
void
PresizedArray<T, N>::fill(T elem)
{
    for (std::size_t i = 0; i < N; i++)
    {
	m_data[i] = elem;
    }
    m_currentSize = N;
}

template <typename T, std::size_t N>
void
PresizedArray<T, N>::insert(T elem)
{
    if (m_currentSize == N)
    {
	SLIM_DEBUG_EXIT("Inserting data in a full PresizedArray of type ", typeid(T).name());
    }
    m_data[m_currentSize] = elem;
    m_currentSize++;
}

template <typename T, std::size_t N>
std::size_t
PresizedArray<T, N>::getSize() const
{
    return m_currentSize;
}


template <typename T, std::size_t N>
template <typename ...Args>
void
PresizedArray<T, N>::forEach(void (*function)(const T& elem, Args ...args), Args& ...args) const
{
    std::size_t	i;

    for (i = 0; i < m_currentSize; ++i)
    { 
	function(m_data[i], args...);
    }
}

template <typename T, std::size_t N>
template <typename ...Args>
void
PresizedArray<T, N>::forEach(void (*function)(T& elem, Args ...args), Args&... args)
{
    std::size_t	i;

    for (i = 0; i < m_currentSize; ++i)
    { 
	function(m_data[i], args...);
    }
}

template <typename T, std::size_t N>
template <typename U>
U
PresizedArray<T, N>::minimum(U (*function)(const T& elem)) const
{
    U	minimum = function(m_data[0]);
    U	result = minimum;

    for (const T& elem : m_data)
    {
	result = function(elem);
	if (result < minimum)
	{
	    minimum = result;
	}
    }

    return result;
}

template <typename T, std::size_t N>
template <typename U>
U
PresizedArray<T, N>::maximum(U (*function)(const T& elem)) const
{
    U	maximum = function(m_data[0]);
    U	result = minimum;

    for (const T& elem : m_data)
    {
	result = function(elem);
	if (result > maximum)
	{
	    maximum = result;
	}
    }

    return result;
}


template <typename T, std::size_t N>
const T&
PresizedArray<T, N>::operator[](std::size_t index) const
{
    SLIM_DEBUG_ASSERT(index < N);
    return m_data[index];
}

template <typename T, std::size_t N>
T&
PresizedArray<T, N>::operator[](std::size_t index)
{
    SLIM_DEBUG_ASSERT(index < N);
    return m_data[index];
}

}
}
