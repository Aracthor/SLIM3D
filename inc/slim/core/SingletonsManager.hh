#ifndef SINGLETONS_MANAGER_HH_
# define SINGLETONS_MANAGER_HH_

# include "slim/core/Singleton.hh"

# define SINGLETONS_NUMBER	3

namespace slim
{
namespace core
{

class	SingletonsManager
{
public:
    SingletonsManager();
    ~SingletonsManager();

private:
    void	listSingletons();
    void	initSingletons();
    void	destroySingletons();

private:
    Singleton*	m_singletons[SINGLETONS_NUMBER];
};

}
}

#endif // !SINGLETONS_MANAGER_HH_
