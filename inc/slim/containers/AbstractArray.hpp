#ifndef SLIM_CONTAINERS_ABSTRACT_ARRAY_HPP_
# define SLIM_CONTAINERS_ABSTRACT_ARRAY_HPP_

namespace slim
{
namespace containers
{

// Every class inheriting from T used in this container must have the same size.
template <class T, unsigned int N>
class	AbstractArray
{
public:
    AbstractArray();
    ~AbstractArray();

public:
    inline unsigned int	getSize() const;

public:
    template <class U, typename ...Args>
    void		insert(Args&&... args);

public:
    template <class U>
    inline const U&	operator[](unsigned int index) const;
    template <class U>
    inline U&		operator[](unsigned int index);

private:
    char		m_data[sizeof(T) * N];
    unsigned int	m_size = 0;
};

}
}

# include "AbstractArray.ipp"

#endif // !SLIM_CONTAINERS_ABSTRACT_ARRAY_HPP_
