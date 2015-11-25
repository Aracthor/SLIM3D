#ifndef SLIM_CONTAINERS_SINGLE_WRAP_HPP_
# define SLIM_CONTAINERS_SINGLE_WRAP_HPP_

namespace slim
{
namespace containers
{

template <class T>
class	SingleWrap
{
public:
    SingleWrap();
    ~SingleWrap();

public:
    void	init(const T& data);
    void	destroy();

public:
    inline bool		isInited() const;
    inline const T&	getData() const;
    inline T&		getData();

private:
    char	m_data[sizeof(T)];
    bool	m_inited = false;
};

}
}

# include "SingleWrap.ipp"

#endif // !SLIM_CONTAINERS_SINGLE_WRAP_HPP_
