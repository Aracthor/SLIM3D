#ifndef SLIM_CONTAINERS_LIST_HPP_
# define SLIM_CONTAINERS_LIST_HPP_

# include "slim/containers/ListNode.hpp"

namespace slim
{
namespace containers
{

template <typename T>
class	List
{
public:
    List(memory::Chunk& chunk);
    ~List();

public:
    void		clear();
    void		pushFront(T* elem);
    void		pushBack(T* elem);
    void		popFront();
    void		popBack();

public:
    inline std::size_t		getSize() const;

public:
    template <typename ...Args>
    void		forEach(void (T::*function)(Args ...args), Args& ...args);

private:
    memory::Chunk&	m_chunk;
    std::size_t		m_size;
    ListNode<T>*	m_begin;
    ListNode<T>*	m_end;
};

}
}

# include "List.ipp"

#endif // !SLIM_CONTAINERS_LIST_HPP_
