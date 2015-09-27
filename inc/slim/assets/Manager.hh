#ifndef SLIM_ASSETS_MANAGER_HH_
# define SLIM_ASSETS_MANAGER_HH_

# include <map>
# include <vector>

# include "slim/assets/Asset.hh"
# include "slim/assets/ListenersManager.hh"
# include "slim/containers/Buffer.hh"
# include "slim/core/Singleton.hh"

# define SLIM_ASSETS_FOLDER	"assets"

namespace slim
{
namespace assets
{

class			Manager : public core::Singleton
{
public:
    static Manager	instance;

public:
    Manager();
    ~Manager();

public:
    void	onInit() override;
    void	onDestroy() override;
    void	setExecutablePath(const char* path);

public:
    inline void	addToLoadList(Asset* asset);
    void	loadNeededAssets();
    void	unloadUnneededAssets();
    void	unloadAllAssets();

public:
    inline ListenersManager&	getListenersManager();

private:
    std::map<const char*, std::vector<Asset*>>		m_assets;
    ListenersManager					m_listenersManager;
    containers::Buffer<char, SLIM_ASSETS_MAX_PATH_SIZE>	m_path;
};

}
}

# include "Manager.hpp"

#endif // !SLIM_ASSETS_MANAGER_HH_
