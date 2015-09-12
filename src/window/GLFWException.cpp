//
// GLFWException.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:45:25 2015 Aracthor
// Last Update Sat Sep 12 15:12:19 2015 Aracthor
//

#include "slim/window/GLFWException.hh"

namespace slim
{
namespace window
{

GLFWException::GLFWException(const char* message, const char* file, const char* function, int line) :
    debug::Exception(message, file, function, line)
{
}

GLFWException::~GLFWException() throw()
{
}

}
}
