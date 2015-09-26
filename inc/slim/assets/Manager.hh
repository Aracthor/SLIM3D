#ifndef SLIM_ASSETS_MANAGER_HH_
# define SLIM_ASSETS_MANAGER_HH_

# include <map>
# include <vector>

# include "slim/assets/Asset.hh"
# include "slim/core/Singleton.hh"

# define SLIM_ASSETS_FOLDER	"assets"

namespace slim
{
namespace assets
{

class		Manager : public core::Singleton
{
public:
    static Manager	instance;

public:
    Manager();
    ~Manager();

public:
    void	onInit() override;
    void	onDestroy() override;
    inline void	setExecutablePath(const char* path);

public:
    void	addToLoadList(Asset* asset);

private:
    const char*	m_path = nullptr;
};

}
}

# include "Manager.hpp"

#endif // !SLIM_ASSETS_MANAGER_HH_
