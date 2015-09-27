#ifndef SLIM_ASSETS_LISTENERS_MANAGER_HH_
# define SLIM_ASSETS_LISTENERS_MANAGER_HH_

# include <map>

# include "slim/assets/IListener.hh"
# include "slim/assets/IListenerList.hh"

namespace slim
{
namespace assets
{

class	ListenersManager
{
public:
    ListenersManager();
    ~ListenersManager();

public:
    template <class ASSET> // Must inherit from class slim::asset::Asset.
    inline void	registerAssetType();

public:
    template <class ASSET> // Must inherit from class slim::asset::Asset.
    void	addAsset(const ASSET* asset);
    template <class ASSET> // Must inherit from class slim::asset::Asset.
    void	addListener(IListener<ASSET>* listener, const ASSET* asset);

public:
    void	onLoad(const Asset* asset);

private:
    std::map<const char*, IListenerList*>	m_listenerLists;
};

}
}

# include "ListenersManager.hpp"

#endif // !SLIM_ASSETS_LISTENERS_MANAGER_HH_
