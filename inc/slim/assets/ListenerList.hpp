namespace slim
{
namespace assets
{

template <class ASSET>
ListenerList<ASSET>::ListenerList()
{
}

template <class ASSET>
ListenerList<ASSET>::~ListenerList()
{
}


template <class ASSET>
const char*
ListenerList<ASSET>::getType() const
{
    return ASSET::typeName;
}

}
}
