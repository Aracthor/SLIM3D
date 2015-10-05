#ifndef SLIM_ASSETS_MANAGER_HH_
# define SLIM_ASSETS_MANAGER_HH_

# include <map>
# include <vector>

# include "slim/assets/ListenersManager.hh"
# include "slim/containers/Buffer.hh"
# include "slim/core/Singleton.hh"

# define SLIM_ASSETS_FOLDER		"../assets"
# define SLIM_ASSETS_MAX_PATH_SIZE	0x1000

namespace slim
{
namespace assets
{

class			Asset;

class			Manager : public core::Singleton
{
public:
    static Manager	instance;

public:
    Manager();
    ~Manager();

public:
    bool	onInit() override;
    void	onDestroy() override;
    void	setExecutablePath(const char* path);

public:
    inline void	addListener(Listener* listener, const Asset* asset);
    template <class ASSET> // ASSET must inherit from slim::assets::Asset.
    void	registerAsset(ASSET* asset);
    template <class ASSET> // ASSET must inherit from slim::assets::Asset.
    inline void	registerAssetType();

public:
    void	loadNeededAssets();
    void	unloadUnneededAssets();
    void	unloadAllAssets();

private:
    void	addToLoadList(Asset* asset);
    void	load(Asset* asset);
    void	unload(Asset* asset);

private:
    std::map<const char*, std::vector<Asset*>>		m_assets;
    ListenersManager					m_listenersManager;
    containers::Buffer<char, SLIM_ASSETS_MAX_PATH_SIZE>	m_path;
};

}
}

# include "Manager.hpp"

#endif // !SLIM_ASSETS_MANAGER_HH_
