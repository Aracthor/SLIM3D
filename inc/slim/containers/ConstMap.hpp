#ifndef SLIM_CONTAINERS_CONST_MAP_HPP_
# define SLIM_CONTAINERS_CONST_MAP_HPP_

namespace slim
{
namespace containers
{

template <typename T, typename U>
class	ConstMap
{
public:
    ConstMap(const T* keys, const U* values);
    ~ConstMap();

public:
    inline const U&	operator[](const T& key) const;

private:
    unsigned int	getIndexOf(const T& key) const;

private:
    const T*		m_keys;
    const U*		m_values;
};

}
}

# include "ConstMap.ipp"

#endif // !SLIM_CONTAINERS_CONST_MAP_HPP_
