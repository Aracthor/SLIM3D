#ifndef SLIM_ASSETS_MANAGER_HPP_
# define SLIM_ASSETS_MANAGER_HPP_

# include "slim/containers/Buffer.hpp"
# include "slim/core/Singleton.hpp"

# define SLIM_ASSETS_MAX_PATH_SIZE	0x200
# define SLIM_ASSETS_FOLDER		"assets"

namespace slim
{
namespace assets
{

class			Manager : public core::Singleton
{
public:
    static Manager	instance;
    
public:
    Manager();
    ~Manager();

public:
    bool		onInit() override;
    void		onDestroy() override;
    void		setExecutablePath(const char* path);

private:
    containers::Buffer<char, SLIM_ASSETS_MAX_PATH_SIZE>	m_path;
};

}
}

#endif // !SLIM_ASSETS_MANAGER_HPP_
