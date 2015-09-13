#ifndef SLIM_WINDOW_MONITORS_MANAGER_HH_
# define SLIM_WINDOW_MONITORS_MANAGER_HH_

# include <map> // TODO implement our own.

# include "slim/core/Singleton.hh"
# include "slim/window/Window.hh"

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
    inline void		addWindow(GLFWwindow* signature, Window* window);
    inline void		removeWindow(GLFWwindow* signature);
    inline Window*	getWindow(GLFWwindow* signature);

protected:
    void	onInit() override;
    void	onDestroy() override;

private:
    std::map<GLFWwindow*, Window*>	m_windows;
};

}
}

# include "MonitorsManager.hpp"

#endif // !SLIM_WINDOW_MONITORS_MANAGER_HH_
