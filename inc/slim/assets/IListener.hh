#ifndef SLIM_ASSETS_ILISTENER_HH_
# define SLIM_ASSETS_ILISTENER_HH_

namespace slim
{
namespace assets
{

template <class ASSET> // ASSET must inherit from class slim::assets::Asset
class	IListener
{
public:
    virtual ~IListener() {}

public:
    virtual void	onLoad(const ASSET* asset) = 0;
};

}
}

#endif // !SLIM_ASSETS_ILISTENER_HH_
