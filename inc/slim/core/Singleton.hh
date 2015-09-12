//
// Singleton.hh for SLIM in /home/aracthor/programs/projects/SLIM/core/inc/slim/core//
// 
// Made by aracthor
// 
// Started on  Mon Aug 31 17:22:22 2015 aracthor
// Last Update Sat Sep 12 15:57:00 2015 Aracthor
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
    Singleton();
    virtual ~Singleton();

public:
    void		init();
    void		destroy();

protected:
    virtual void	onInit() = 0;
    virtual void	onDestroy() = 0;

private:
    bool		m_inited;
};

}
}

#endif // !SLIM_CORE_SINGLETON_HH_
