#ifndef SLIM_ASSETS_LISTENER_HPP_
# define SLIM_ASSETS_LISTENER_HPP_

# include <vector>

namespace slim
{
namespace assets
{

class	Asset;

class	Listener
{
public:
    Listener();
    virtual ~Listener();

public:
    virtual void	onAssetsReady();
    virtual void	onAssetsUnloaded();

public:
    void		listen(const Asset* asset);
    void	        onOneAssetReady();
    void	        onOneAssetUnloaded();

public:
    inline unsigned int	getWaitedNumber() const;
    inline bool		isReady() const;

protected:
    std::vector<const Asset*>	m_assets;

private:
    unsigned int	m_waitedNumber = 0;
};

}
}

# include "Listener.ipp"

#endif // !SLIM_ASSETS_LISTENER_HPP_
