//
// Coordinator.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 21:52:22 2015 Aracthor
// Last Update Sat Sep 12 22:03:57 2015 Aracthor
//

#ifndef SLIM_EVENTS_COORDINATOR_HH_
# define SLIM_EVENTS_COORDINATOR_HH_

# include <map> // TODO implement our own

# include "slim/core/Singleton.hh"
# include "slim/window/Window.hh"

# include <GLFW/glfw3.h>

namespace slim
{
namespace events
{

class	Coordinator : public core::Singleton
{
public:
    static Coordinator	instance;

public:
    Coordinator();
    ~Coordinator();

public:
    inline void			addWindow(window::Window* window, const GLFWwindow* glfwWindow);
    inline window::Window*	getWindow(const GLFWwindow* glfwWindow);

public:
    void	onInit() override;
    void	onDestroy() override;

private:
    std::map<const GLFWwindow*, window::Window*>	m_windows;
};

}
}

# include "Coordinator.hpp"

#endif // !SLIM_EVENTS_COORDINATOR_HH_
