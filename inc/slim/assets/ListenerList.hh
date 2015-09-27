#ifndef SLIM_ASSETS_LISTENER_LIST_HH_
# define SLIM_ASSETS_LISTENER_LIST_HH_

# include <map>
# include <vector>

# include "slim/assets/IListenerList.hh"

namespace slim
{
namespace assets
{

template <class ASSET> // Must inherit from class slim::asset::Asset.
class	ListenerList : public IListenerList
{
public:
    ListenerList();
    ~ListenerList();

public:
    inline const char*	getType() const override;

public:
    inline void		addAsset(const ASSET* asset);
    void		addListener(IListener<ASSET>* listener, const ASSET* asset);
    void		onAssetLoad(const ASSET* asset);

private:
    std::map<const ASSET*, std::vector<IListener<ASSET>*>>	m_assets;
};

}
}

# include "ListenerList.hpp"

#endif // !SLIM_ASSETS_LISTENER_LIST_HH_
