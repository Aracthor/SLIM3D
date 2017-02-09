#ifndef SLIM_CONTAINERS_LIST_NODE_HPP_
# define SLIM_CONTAINERS_LIST_NODE_HPP_

# include "slim/memory/Chunk.hpp"

namespace slim
{
namespace containers
{

template <typename T>
class	List;

template <typename T>
class	ListNode
{
public:
    ListNode(T* data);
    ~ListNode();

public:
    inline const T&	operator*() const;
    inline T&		operator*();
    inline const T&	operator->() const;
    inline T&		operator->();

private:
    inline void		deleteData(memory::Chunk& chunk);

private:
    ListNode<T>*	m_next;
    ListNode<T>*	m_prev;
    T*			m_data;

    friend class	List<T>;
};

}
}

# include "ListNode.ipp"

#endif // !SLIM_CONTAINERS_LIST_NODE_HPP_
