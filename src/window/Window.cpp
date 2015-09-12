//
// Window.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:02:37 2015 Aracthor
// Last Update Sat Sep 12 18:35:29 2015 Aracthor
//

#include "slim/window/GLFWException.hh"
#include "slim/window/Window.hh"

namespace slim
{
namespace window
{

Window::Window(Parameters parameters) :
    m_parameters(parameters)
{
    m_window = glfwCreateWindow(parameters.width, parameters.height, parameters.title, nullptr, nullptr);
    if (m_window == nullptr)
    {
	throw GLFWException("Couldn't create window.", __FILE__, __func__, __LINE__);
    }
    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);
}

Window::~Window()
{
    // TODO
}


bool
Window::shouldClose() const
{
    return glfwWindowShouldClose(m_window);
}

}
}
