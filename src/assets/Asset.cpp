#include "slim/assets/Asset.hh"

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

}
}
