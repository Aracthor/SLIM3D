#include "slim/debug/assert.hpp"

#include <cstring>

namespace slim
{
namespace containers
{

template <class T, unsigned int N>
AbstractArray<T, N>::AbstractArray()
{
}

template <class T, unsigned int N>
AbstractArray<T, N>::~AbstractArray()
{
}


template <class T, unsigned int N>
unsigned int
AbstractArray<T, N>::getSize() const
{
    return m_size;
}


template <class T, unsigned int N>
template <class U, typename ...Args>
void
AbstractArray<T, N>::insert(Args&&... args)
{
    U	elem(args...);

    memcpy(&(reinterpret_cast<U*>(m_data))[m_size], &elem, sizeof(U));
    (reinterpret_cast<U*>(m_data))[m_size].alloc(42);
    m_size++;

}


template <class T, unsigned int N>
template <class U>
const U&
AbstractArray<T, N>::operator[](unsigned int index) const
{
    return reinterpret_cast<const U*>(m_data)[index];
}

template <class T, unsigned int N>
template <class U>
U&
AbstractArray<T, N>::operator[](unsigned int index)
{
    return reinterpret_cast<U*>(m_data)[index];
}

}
}
