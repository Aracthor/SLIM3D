#ifndef SLIM_ASSETS_LISTENERS_MANAGER_HH_
# define SLIM_ASSETS_LISTENERS_MANAGER_HH_

# include <map>

# include "slim/assets/Listener.hh"

namespace slim
{
namespace assets
{

class	Asset;

class	ListenersManager
{
public:
    ListenersManager();
    ~ListenersManager();

public:
    template <class ASSET> // Must inherit from class slim::asset::Asset.
    inline void	registerAssetType();

public:
    void	addAsset(const Asset* asset);
    void	addListener(Listener* listener, const Asset* asset);

public:
    void	onLoad(const Asset* asset);
    void	onUnload(const Asset* asset);

private:
    typedef std::map<const Asset*, std::vector<Listener*>>	ListenerList;

private:
    std::map<const char*, ListenerList>	m_listenerLists;
};

}
}

# include "ListenersManager.hpp"

#endif // !SLIM_ASSETS_LISTENERS_MANAGER_HH_
