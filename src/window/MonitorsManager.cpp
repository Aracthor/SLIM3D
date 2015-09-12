//
// MonitorsManager.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 14:43:28 2015 Aracthor
// Last Update Sat Sep 12 15:58:46 2015 Aracthor
//

#include "slim/core/attributes.h"
#include "slim/debug/LogManager.hh"
#include "slim/window/MonitorsManager.hh"
#include "slim/window/GLFWException.hh"
#include <iostream> // DEBUG

namespace slim
{
namespace window
{

MonitorsManager
MonitorsManager::instance;


MonitorsManager::MonitorsManager()
{
}

MonitorsManager::~MonitorsManager()
{
}


static void error_callback(SLIM_CORE_UNUSED int error, const char* description)
{
    debug::LogManager::instance.graphics.writeError(description);
}


void
MonitorsManager::onInit()
{
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
	throw GLFWException("Error in GLFW initialization.", __FILE__, __func__, __LINE__);
    }
}

void
MonitorsManager::onDestroy()
{
    glfwTerminate();
}

}
}
