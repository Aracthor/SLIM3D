//
// MonitorsManager.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:43:43 2015 Aracthor
// Last Update Sun Sep 13 09:29:06 2015 Aracthor
//

namespace slim
{
namespace window
{

void
MonitorsManager::addWindow(GLFWwindow* signature, Window* window)
{
    m_windows[signature] = window;
}

void
MonitorsManager::removeWindow(GLFWwindow* signature)
{
    m_windows.erase(signature);
}

Window*
MonitorsManager::getWindow(GLFWwindow* signature)
{
    return m_windows[signature];
}

}
}
