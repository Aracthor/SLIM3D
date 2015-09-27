#ifndef SLIM_ASSETS_ILISTENER_LIST_HH_
# define SLIM_ASSETS_ILISTENER_LIST_HH_

namespace slim
{
namespace assets
{

class	IListenerList
{
public:
    virtual ~IListenerList() {}

public:
    virtual const char*	getType() const = 0;
};

}
}

#endif // !SLIM_ASSETS_ILISTENER_LIST_HH_
