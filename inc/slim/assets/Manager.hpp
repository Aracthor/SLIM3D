#ifndef SLIM_ASSETS_MANAGER_HPP_
# define SLIM_ASSETS_MANAGER_HPP_

# include "slim/core/FileAccesser.hpp"
# include "slim/core/Singleton.hpp"

# define SLIM_ASSETS_FOLDER		"assets"

namespace slim
{
namespace assets
{

class			Manager : public core::Singleton,
				  public core::FileAccesser
{
public:
    static Manager	instance;
    
public:
    Manager();
    ~Manager();

public:
    bool		onInit() override;
    void		onDestroy() override;
};

}
}

#endif // !SLIM_ASSETS_MANAGER_HPP_
