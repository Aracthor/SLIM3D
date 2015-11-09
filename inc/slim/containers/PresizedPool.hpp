#ifndef SLIM_CONTAINERS_PRESIZED_POOL_HPP_
# define SLIM_CONTAINERS_PRESIZED_POOL_HPP_

# include "slim/containers/IPool.hpp"
# include "slim/data.hpp"

# include <cstddef>

namespace slim
{
namespace containers
{

template <typename T, std::size_t N>
class	PresizedPool : public IPool<T>
{
public:
    PresizedPool();
    ~PresizedPool();

public:
    void	clear() override;
    template <typename ...Args>
    T*		create(Args&& ...args);
    void	destroy(T& elem) override;

private:
    byte	m_data[N * sizeof(T)];
    bool	m_busy[N];
};

}
}

# include "PresizedPool.ipp"

#endif // !SLIM_CONTAINERS_PRESIZED_POOL_HPP_
