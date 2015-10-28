#ifndef SLIM_ASSETS_SINGLE_FILE_ASSET_HPP_
# define SLIM_ASSETS_SINGLE_FILE_ASSET_HPP_

# include "slim/assets/Asset.hpp"

namespace slim
{
namespace assets
{

class	SingleFileAsset : public Asset
{
public:
    SingleFileAsset(const char* const type, const char* const name, const char* const file);
    SingleFileAsset(const SingleFileAsset& reference);
    virtual ~SingleFileAsset();

public:
    bool		loadData(const char* const path) override;

public:
    inline const char*	getFile() const;

protected:
    virtual bool	loadFromFile(const char* const path) = 0;

protected:
    const char* const	m_file;
};

}
}

# include "SingleFileAsset.ipp"

#endif // !SLIM_ASSETS_SINGLE_FILE_ASSET_HPP_
