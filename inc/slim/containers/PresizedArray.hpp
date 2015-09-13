//
// PresizedArray.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 16:46:24 2015 Aracthor
// Last Update Sun Sep 13 13:24:54 2015 Aracthor
//

#include <typeinfo>

#include "slim/core/templates.hh"
#include "slim/debug/assert.hh"
#include "slim/debug/Exception.hh"

#include <cstring>

namespace slim
{
namespace containers
{

template <typename T, unsigned int N>
PresizedArray<T, N>::PresizedArray()
{
    m_currentSize = 0;
}

template <typename T, unsigned int N>
PresizedArray<T, N>::PresizedArray(T defaultData)
{
    this->fill(defaultData);
}

template <typename T, unsigned int N>
PresizedArray<T, N>::~PresizedArray()
{
}


template <typename T, unsigned int N>
void
PresizedArray<T, N>::fill(T elem)
{
    for (unsigned int i = 0; i < N; i++)
    {
	m_data[i] = elem;
    }
    m_currentSize = N;
}

template <typename T, unsigned int N>
void
PresizedArray<T, N>::insert(T elem)
{
    if (m_currentSize == N)
    {
	char	buffer[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

	strncpy(buffer, "Inserting data in a full PresizedArray of type ", SLIM_DEBUG_MESSAGE_BUFFER_SIZE);
	strncat(buffer, typeid(T).name(), SLIM_DEBUG_MESSAGE_BUFFER_SIZE - strlen(buffer));
	throw debug::Exception(buffer, __FILE__, __func__, __LINE__);
    }
    m_data[m_currentSize] = elem;
    m_currentSize++;
}

template <typename T, unsigned int N>
unsigned int
PresizedArray<T, N>::getSize() const
{
    return m_currentSize;
}


template <typename T, unsigned int N>
void
PresizedArray<T, N>::forEach(void (*function)(const T& elem)) const
{
    for (const T& elem : m_data)
    {
	function(elem);
    }
}

template <typename T, unsigned int N>
void
PresizedArray<T, N>::forEach(void (*function)(T& elem))
{
    for (T& elem : m_data)
    {
	function(elem);
    }
}

template <typename T, unsigned int N>
template <typename U>
void
PresizedArray<T, N>::forEach(void (*function)(const T& elem, const U& param), const U& param) const
{
    for (T& elem : m_data)
    {
	function(elem, param);
    }
}

template <typename T, unsigned int N>
template <typename U>
void
PresizedArray<T, N>::forEach(void (*function)(T& elem, const U& param), const U& param)
{
    for (T& elem : m_data)
    {
	function(elem, param);
    }
}

template <typename T, unsigned int N>
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

template <typename T, unsigned int N>
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


template <typename T, unsigned int N>
const T&
PresizedArray<T, N>::operator[](unsigned int index) const
{
    SLIM_DEBUG_ASSERT(index < N);
    return m_data[index];
}

template <typename T, unsigned int N>
T&
PresizedArray<T, N>::operator[](unsigned int index)
{
    SLIM_DEBUG_ASSERT(index < N);
    return m_data[index];
}

}
}
