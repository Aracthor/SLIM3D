//
// SingletonsManager.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/core/inc/slim3d/core//
// 
// Made by aracthor
// 
// Started on  Mon Aug 31 17:31:31 2015 aracthor
// Last Update Mon Aug 31 17:52:35 2015 Aracthor
//

#ifndef SINGLETONS_MANAGER_HH_
# define SINGLETONS_MANAGER_HH_

# include "slim3d/core/Singleton.hh"

# define SINGLETONS_NUMBER	0

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
