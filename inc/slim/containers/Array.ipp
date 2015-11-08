#include "slim/debug/assert.hpp"

#include "slim/string.h"

namespace slim
{
namespace containers
{

template <typename T>
Array<T>::Array(memory::Chunk& chunk) :
    m_chunk(chunk),
    m_data(nullptr),
    m_size(0),
    m_maxSize(0)
{
}

template <typename T>
Array<T>::Array(memory::Chunk& chunk, std::size_t size) :
    m_chunk(chunk),
    m_data(chunk.alloc(size * sizeof(T))),
    m_size(0),
    m_maxSize(size)
{
}

template <typename T>
Array<T>::Array(memory::Chunk& chunk, const Array<T>& array) :
    m_chunk(chunk),
    m_data(chunk.alloc(array.getSize() * sizeof(T))),
    m_size(array.getSize()),
    m_maxSize(array.getSize())
{
    memcpy(m_data, &array[0], m_size * sizeof(T));
}

template <typename T>
Array<T>::~Array()
{
    if (m_data != nullptr)
    {
	m_chunk.free(m_data);
    }
}


template <typename T>
void
Array<T>::insert(T elem)
{
    if (m_size == m_maxSize)
    {
	this->resize(2 * m_size);
    }

    m_data[m_size] = elem;
    m_size++;
}

template <typename T>
void
Array<T>::resize(std::size_t size)
{
    m_chunk.realloc(m_data, size * sizeof(T));
    m_maxSize = size;
    if (m_size > size)
    {
	m_size = size;
    }
}

template <typename T>
std::size_t
Array<T>::getSize() const
{
    return m_size;
}

template <typename T>
std::size_t
Array<T>::getMaxSize() const
{
    return m_maxSize;
}


template <typename T>
const T&
Array<T>::operator[](std::size_t index) const
{
    SLIM_DEBUG_ASSERT(index < m_size);
    return m_data[index];
}

template <typename T>
T&
Array<T>::operator[](std::size_t index)
{
    SLIM_DEBUG_ASSERT(index < m_size);
    return m_data[index];
}

}
}
