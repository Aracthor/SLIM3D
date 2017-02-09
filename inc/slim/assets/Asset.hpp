#ifndef SLIM_ASSETS_ASSET_HPP_
# define SLIM_ASSETS_ASSET_HPP_

# include "slim/assets/Listener.hpp"
# include "slim/memory/Chunk.hpp"

namespace slim
{
namespace assets
{

class	Asset : public Listener
{
public:
    template <class ASSET, typename ...Args> // ASSET must inherit from this class.
    static ASSET*	create(memory::Chunk& chunk, Args&&... args);

protected:
    Asset(const char* const type, const char* const name);
    Asset(const Asset& reference);

public:
    virtual ~Asset();

public:
    bool		load(const char* const path);
    void		unload();
    void		setNeeded(bool needed) const;

protected:
    virtual bool	loadData(const char* const path);
    virtual void	unloadData();

public:
    inline const char*	getType() const;
    inline const char*	getName() const;
    inline bool		isNeeded() const;
    inline bool		isLoaded() const;

private:
    const char* const	m_type;
    const char* const	m_name;
    mutable bool	m_needed = false;
    bool	        m_loaded = false;
};

}
}

# include "Asset.ipp"

#endif // !SLIM_ASSETS_ASSET_HPP_
