#include "slim/core/attributes.h"
#include "slim/debug/LogManager.hh"
#include "slim/window/MonitorsManager.hh"
#include "slim/window/GLFWException.hh"

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


static void error_callback(SLIM_CORE_UNUSED(int, error), const char* description)
{
    debug::LogManager::instance.graphics.error << description << debug::LogStream::endline;
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
