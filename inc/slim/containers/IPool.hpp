#ifndef SLIM_CONTAINERS_IPOOL_HPP_
# define SLIM_CONTAINERS_IPOOL_HPP_

namespace slim
{
namespace containers
{

template <typename T>
class	IPool
{
public:
    virtual ~IPool() {}

public:
    virtual void	clear() = 0;
    virtual void	destroy(T& element) = 0;
};

}
}

#endif // !SLIM_CONTAINERS_IPOOL_HPP_
