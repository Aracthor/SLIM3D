//
// Window.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:02:37 2015 Aracthor
// Last Update Sat Sep 12 15:46:44 2015 Aracthor
//

namespace slim
{
namespace window
{

unsigned int
Window::getWidth() const
{
    return m_parameters.width;
}

unsigned int
Window::getHeight() const
{
    return m_parameters.height;
}

bool
Window::isFullscreen() const
{
    return m_parameters.fullscreen;
}

const char*
Window::getTitle() const
{
    return m_parameters.title;
}

}
}
