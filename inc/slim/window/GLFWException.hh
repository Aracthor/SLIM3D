//
// GLFWException.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:46:24 2015 Aracthor
// Last Update Sat Sep 12 14:47:17 2015 Aracthor
//

#ifndef SLIM_WINDOW_GLFW_EXCEPTION_HH_
# define SLIM_WINDOW_GLFW_EXCEPTION_HH_

# include "slim/debug/Exception.hh"

namespace slim
{
namespace window
{

class	GLFWException : public debug::Exception
{
public:
    GLFWException(const char* message, const char* file, const char* function, int line);
    ~GLFWException() throw();
};

}
}

# include "GLFWException.hpp"

#endif // !SLIM_WINDOW_G_L_F_W_EXCEPTION_HH_
