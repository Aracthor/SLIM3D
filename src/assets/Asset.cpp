#include "slim/assets/Asset.hh"
#include "slim/debug/assert.hh"

#include <iostream> // DEBUG

namespace slim
{
namespace assets
{

Asset::Asset(const char* const type, const char* const name) :
    m_type(type),
    m_name(name)
{
}

Asset::Asset(const Asset& reference) :
    Asset(reference.getType(), reference.getName())
{
}

Asset::~Asset()
{
}


bool
Asset::load(const char* const path)
{
    SLIM_DEBUG_ASSERT(m_loaded == false);
    m_loaded = true;
    return this->loadData(path);
}

void
Asset::unload()
{
    SLIM_DEBUG_ASSERT(m_loaded == true);
    m_loaded = false;
    this->unloadData();
}

void
Asset::setNeeded(bool needed) const
{
    m_needed = needed;
    for (const Asset* asset : m_assets)
    {
	asset->setNeeded(needed);
    }
}

}
}
