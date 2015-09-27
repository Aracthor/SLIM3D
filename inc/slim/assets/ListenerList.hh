#ifndef SLIM_ASSETS_LISTENER_LIST_HH_
# define SLIM_ASSETS_LISTENER_LIST_HH_

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
};

}
}

# include "ListenerList.hpp"

#endif // !SLIM_ASSETS_LISTENER_LIST_HH_
