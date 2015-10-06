#ifndef SLIM_CONTAINERS_IARRAY_HH_
# define SLIM_CONTAINERS_IARRAY_HH_

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
    virtual void		insert(T elem) = 0;
    virtual unsigned int	getSize() const = 0;

public:
    virtual const T&	operator[](unsigned int index) const = 0;
    virtual T&		operator[](unsigned int index) = 0;
};

}
}

#endif // !SLIM_CONTAINERS_IARRAY_HH_
