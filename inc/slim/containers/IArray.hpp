#ifndef SLIM_CONTAINERS_IARRAY_HPP_
# define SLIM_CONTAINERS_IARRAY_HPP_

# include <cstddef>

namespace slim
{
namespace containers
{

template <typename T>
class	IArray
{
public:
    virtual ~IArray() {}

public:
    virtual void	insert(T elem) = 0;
    virtual std::size_t	getSize() const = 0;

public:
    virtual const T&	operator[](std::size_t index) const = 0;
    virtual T&		operator[](std::size_t index) = 0;
};

}
}

#endif // !SLIM_CONTAINERS_IARRAY_HPP_
