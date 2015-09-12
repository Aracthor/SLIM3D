//
// Coordinator.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 21:52:33 2015 Aracthor
// Last Update Sat Sep 12 22:00:11 2015 Aracthor
//

namespace slim
{
namespace events
{

void
Coordinator::addWindow(window::Window* window, const GLFWwindow* glfwWindow)
{
    m_windows[glfwWindow] = window;
}

window::Window*
Coordinator::getWindow(const GLFWwindow* glfwWindow)
{
    return m_windows[glfwWindow];
}

}
}
