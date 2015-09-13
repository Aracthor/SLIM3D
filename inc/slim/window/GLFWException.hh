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

#endif // !SLIM_WINDOW_G_L_F_W_EXCEPTION_HH_
