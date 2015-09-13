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
