#include "slim/debug/assert.hpp"

namespace slim
{
namespace containers
{

template <typename T, unsigned int N>
Buffer<T, N>::Buffer() :
    m_size(0)
{
}

template <typename T, unsigned int N>
Buffer<T, N>::~Buffer()
{
}


template <typename T, unsigned int N>
void
Buffer<T, N>::clear()
{
    m_size = 0;
}


template <typename T, unsigned int N>
void
Buffer<T, N>::resetToSize(unsigned int size)
{
    SLIM_DEBUG_ASSERT(size <= m_size);
    m_size = size;
    m_data[m_size] = '\0';
}


template <typename T, unsigned int N>
bool
Buffer<T, N>::isEmpty() const
{
    return (m_size == 0);
}

template <typename T, unsigned int N>
unsigned int
Buffer<T, N>::getSize() const
{
    return m_size;
}

template <typename T, unsigned int N>
const T*
Buffer<T, N>::getData() const
{
    return m_data;
}


template <typename T, unsigned int N>
T
Buffer<T, N>::operator[](unsigned int index) const
{
    SLIM_DEBUG_ASSERT(index < m_size);
    return m_data[index];
}

template <typename T, unsigned int N>
T&
Buffer<T, N>::operator[](unsigned int index)
{
    SLIM_DEBUG_ASSERT(index < N);
    return m_data[index];
}


template <typename T, unsigned int N>
Buffer<T, N>&
Buffer<T, N>::operator<<(T c)
{
    SLIM_DEBUG_ASSERT(m_size + 1 < N);
    m_data[m_size] = c;
    m_size++;

    return *this;
}

template <typename T, unsigned int N>
Buffer<T, N>&
Buffer<T, N>::operator<<(const T* str)
{
    while (*str)
    {
	*this << *str;
	str++;
    }

    return *this;
}

template <typename T, unsigned int N>
Buffer<T, N>&
Buffer<T, N>::operator<<(T* str)
{
    return (*this << static_cast<const T*>(str));
}

template <typename T, unsigned int N>
template <unsigned int M>
Buffer<T, N>&
Buffer<T, N>::operator<<(const Buffer<T, M> buffer)
{
    return (*this << buffer.getData());
}

template <typename T, unsigned int N>
template <typename U>
Buffer<T, N>&
Buffer<T, N>::operator<<(U* ptr)
{
    return (*this << reinterpret_cast<unsigned long long>(ptr));
}


template <typename T, unsigned int N>
template <typename U>
Buffer<T, N>&
Buffer<T, N>::operator<<(U n)
{
    if (n < 0)
    {
	*this << static_cast<T>('-');
	n = -n;
    }
    if (n >= 10)
    {
	*this << (n / 10);
	*this << (n % 10);
    }
    else
    {
	*this << static_cast<T>(static_cast<T>(n) + static_cast<T>('0'));
    }

    return *this;
}

}
}
