#include "slim/assets/Manager.hh"

namespace slim
{
namespace assets
{

template <class ASSET, typename ...Args>
ASSET*
Asset::create(Args&&... args)
{
    ASSET*	asset = new ASSET(args...);

    Manager::instance.registerAsset(asset);

    return asset;
}


template <class ASSET>
void
Asset::addListener(IListener<ASSET>* listener) const
{
    SLIM_DEBUG_ASSERT(this->getType() == ASSET::typeName); // Else, the static cast would fail.
    Manager::instance.addListener(listener, static_cast<const ASSET*>(this));
}


const char*
Asset::getType() const
{
    return m_type;
}

const char*
Asset::getName() const
{
    return m_name;
}

bool
Asset::isNeeded() const
{
    return m_needed;
}

bool
Asset::isLoaded() const
{
    return m_loaded;
}

void
Asset::setNeeded(bool needed) const
{
    m_needed = needed;
}

}
}
