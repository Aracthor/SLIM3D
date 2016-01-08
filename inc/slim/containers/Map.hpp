#ifndef SLIM_CONTAINERS_MAP_HPP_
# define SLIM_CONTAINERS_MAP_HPP_

# include "slim/containers/Array.hpp"

namespace slim
{
namespace containers
{

template <typename T, typename U>
class	Map
{
public:
    Map(memory::Chunk& chunk);
    virtual ~Map();

public:
    void	insert(T key, U value);

public:
    inline std::size_t	getSize() const;

public:
    const U&		operator[](T key) const;

protected:
    virtual bool	compare(T key1, T key2) const;

private:
    std::size_t	getKeyIndex(T key) const;

private:
    Array<T>	m_keys;
    Array<U>	m_values;
};

}
}

# include "slim/containers/Map.ipp"

#endif // !SLIM_CONTAINERS_MAP_HPP_
