namespace slim
{
namespace containers
{

template <typename T>
ListNode<T>::ListNode(T* data) :
    m_next(nullptr),
    m_prev(nullptr),
    m_data(data)
{
}

template <typename T>
ListNode<T>::~ListNode()
{
}


template <typename T>
const T&
ListNode<T>::operator*() const
{
    return *m_data;
}

template <typename T>
T&
ListNode<T>::operator*()
{
    return *m_data;
}

template <typename T>
const T&
ListNode<T>::operator->() const
{
    return *m_data;
}

template <typename T>
T&
ListNode<T>::operator->()
{
    return *m_data;
}


template <typename T>
void
ListNode<T>::deleteData(memory::Chunk& chunk)
{
    chunk.destroy(m_data);
}

}
}
