#include "slim/assets/Asset.hh"
#include "slim/debug/assert.hh"

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

}
}
