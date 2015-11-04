#ifndef SINGLETONS_MANAGER_HPP_
# define SINGLETONS_MANAGER_HPP_

# include <vector> // TODO create our own

# include "slim/core/Singleton.hpp"

namespace slim
{
namespace core
{

class	SingletonsManager
{
public:
    SingletonsManager();
    ~SingletonsManager();

public:
    void	addSingleton(Singleton* singleton);

public:
    void	initSingletons();
    void	destroySingletons();

private:
    bool			m_inited;
    std::vector<Singleton*>	m_singletons;
};

}
}

#endif // !SINGLETONS_MANAGER_HPP_
