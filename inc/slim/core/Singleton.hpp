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
    bool		init();
    void		destroy();

protected:
    virtual bool	onInit() = 0;
    virtual void	onDestroy() = 0;

private:
    bool		m_inited;
};

}
}

#endif // !SLIM_CORE_SINGLETON_HH_
