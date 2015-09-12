//
// Singleton.hh for SLIM in /home/aracthor/programs/projects/SLIM/core/inc/slim/core//
// 
// Made by aracthor
// 
// Started on  Mon Aug 31 17:22:22 2015 aracthor
// Last Update Mon Aug 31 17:52:56 2015 Aracthor
//

#ifndef SLIM_CORE_SINGLETON_HH_
# define SLIM_CORE_SINGLETON_HH_

namespace slim
{
namespace core
{

class	Singleton
{
protected:
    virtual ~Singleton() {}

public:
    virtual void	init() = 0;
    virtual void	destroy() = 0;
};

}
}

#endif // !SLIM_CORE_SINGLETON_HH_
