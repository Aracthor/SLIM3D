#ifndef SLIM_RESOURCES_MANAGER_HH_
# define SLIM_RESOURCES_MANAGER_HH_

# include "slim/core/Singleton.hh"

namespace slim
{
namespace resources
{

class	Manager : public core::Singleton
{
public:
    Manager();
    ~Manager();

public:
    void	onInit() override;
    void	onDestroy() override;
    inline void	setExecutablePath(const char* path);

private:
    const char*	m_path = nullptr;
};

}
}

# include "Manager.hpp"

#endif // !SLIM_RESOURCES_MANAGER_HH_
