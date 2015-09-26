#ifndef SLIM_ASSETS_ASSET_HH_
# define SLIM_ASSETS_ASSET_HH_

namespace slim
{
namespace assets
{

class	Asset
{
public:
    Asset(const char* const type, const char* const name);
    Asset(const Asset& reference);
    virtual ~Asset();

public:
    inline const char*	getType() const;
    inline const char*	getName() const;

private:
    const char* const	m_type;
    const char* const	m_name;
};

}
}

# include "Asset.hpp"

#endif // !SLIM_ASSETS_ASSET_HH_
