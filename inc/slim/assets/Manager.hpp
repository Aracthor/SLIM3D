#ifndef SLIM_ASSETS_MANAGER_HPP_
# define SLIM_ASSETS_MANAGER_HPP_

# include <map>
# include <vector>

# include "slim/assets/ListenersManager.hpp"
# include "slim/containers/Buffer.hpp"
# include "slim/containers/SingleWrap.hpp"
# include "slim/core/Singleton.hpp"
# include "slim/memory/Chunk.hpp"

# include "slim/memory/units.h"

# define SLIM_ASSETS_FOLDER		"../assets"
# define SLIM_ASSETS_MAX_PATH_SIZE	0x1000
# define SLIM_ASSETS_MANAGER_SIZE	(10 * SLIM_MEMORY_KIBIBYTE)

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
    containers::SingleWrap<memory::Chunk>		m_memory;
    std::map<const char*, std::vector<Asset*>>		m_assets;
    ListenersManager					m_listenersManager;
    containers::Buffer<char, SLIM_ASSETS_MAX_PATH_SIZE>	m_path;
};

}
}

# include "Manager.ipp"

#endif // !SLIM_ASSETS_MANAGER_HPP_
