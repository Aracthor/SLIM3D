#include "slim/assets/Manager.hpp"

namespace slim
{
namespace assets
{

template <class ASSET, typename ...Args>
ASSET*
Asset::create(memory::Chunk& chunk, Args&&... args)
{
    ASSET*	asset = chunk.create<ASSET>(args...);

    Manager::instance.registerAsset(asset);

    return asset;
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

}
}
