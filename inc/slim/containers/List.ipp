#include "slim/debug/assert.hpp"

namespace slim
{
namespace containers
{

template <typename T>
List<T>::List(memory::Chunk& chunk) :
    m_chunk(chunk),
    m_size(0),
    m_begin(nullptr),
    m_end(nullptr)
{
}

template <typename T>
List<T>::~List()
{
    this->clear();
}


template <typename T>
void
List<T>::clear()
{
    ListNode<T>*	node;

    while (m_begin != nullptr)
    {
	node = m_begin;
	m_begin = m_begin->m_next;
	node->deleteData(m_chunk);
	m_chunk.destroy(node);
    }
}

template <typename T>
void
List<T>::pushFront(T* elem)
{
    ListNode<T>*	node = m_chunk.create<ListNode<T>>(elem);

    node->m_next = m_begin;
    m_begin = node;
    if (m_end == nullptr)
    {
	m_end = node;
    }
    m_size++;
}

template <typename T>
void
List<T>::pushBack(T* elem)
{
    ListNode<T>*	node = m_chunk.create<ListNode<T>>(elem);

    node->m_prev = m_end;
    m_end = node;
    if (m_begin == nullptr)
    {
	m_begin = node;
    }
    m_size++;
}

template <typename T>
void
List<T>::popFront()
{
    List<T>*	node = m_begin;

    SLIM_DEBUG_ASSERT(m_begin != nullptr);
    m_begin = m_begin->m_next;
    m_chunk.destroy(node);
    m_size--;
}

template <typename T>
void
List<T>::popBack()
{
    List<T>*	node = m_end;

    SLIM_DEBUG_ASSERT(m_end != nullptr);
    m_end = m_end->m_prev;
    m_chunk.destroy(node);
    m_size--;
}


template <typename T>
std::size_t
List<T>::getSize() const
{
    return m_size;
}


template <typename T>
template <typename ...Args>
void
List<T>::forEach(void (T::*function)(Args ...args), Args& ...args)
{
    ListNode<T>*	element = m_begin;

    while (element != nullptr)
    {
	(**element.*function)(args...);
	element = element->m_next;
    }
}

template <typename T>
template <typename ...Args>
void
List<T>::forEach(void (*function)(const T& element, Args ...args), Args&& ...args) const
{
    const ListNode<T>*	element = m_begin;

    while (element != nullptr)
    {
	function(**element, args...);
	element = element->m_next;
    }
}

template <typename T>
template <typename ...Args>
void
List<T>::forEach(void (*function)(T& element, Args ...args), Args&& ...args)
{
    const ListNode<T>*	element = m_begin;

    while (element != nullptr)
    {
	function(*element, args...);
	element = element->m_next;
    }
}

}
}
