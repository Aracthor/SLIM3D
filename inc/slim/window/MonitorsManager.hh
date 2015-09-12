//
// MonitorsManager.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:43:38 2015 Aracthor
// Last Update Sat Sep 12 15:58:32 2015 Aracthor
//

#ifndef SLIM_WINDOW_MONITORS_MANAGER_HH_
# define SLIM_WINDOW_MONITORS_MANAGER_HH_

# include "slim/core/Singleton.hh"

# include <GLFW/glfw3.h>

namespace slim
{
namespace window
{

class	MonitorsManager : public core::Singleton
{
public:
    static MonitorsManager	instance;

private:
    MonitorsManager();
    ~MonitorsManager();

public:
    void	onInit() override;
    void	onDestroy() override;
};

}
}

# include "MonitorsManager.hpp"

#endif // !SLIM_WINDOW_MONITORS_MANAGER_HH_
