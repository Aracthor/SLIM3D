#ifndef SLIM_ASSETS_EXCEPTION_HH_
# define SLIM_ASSETS_EXCEPTION_HH_

# include "slim/assets/Asset.hh"
# include "slim/debug/Exception.hh"

namespace slim
{
namespace assets
{

class	Exception : public debug::Exception
{
public:
    Exception(const Asset& asset, const char* message, const char* file, const char* function, int line);
    virtual ~Exception() throw();

public:
    inline const Asset&	getAsset() const;

private:
    const Asset&	m_asset;
};

}
}

# include "Exception.hpp"

#endif // !SLIM_ASSETS_EXCEPTION_HH_
