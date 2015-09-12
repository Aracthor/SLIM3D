//
// Window.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:02:37 2015 Aracthor
// Last Update Sat Sep 12 15:59:16 2015 Aracthor
//

#include "slim/window/Window.hh"

namespace slim
{
namespace window
{

Window::Window(Parameters parameters) :
    m_parameters(parameters)
{
    m_window = glfwCreateWindow(parameters.width, parameters.height, parameters.title, nullptr, nullptr);
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
