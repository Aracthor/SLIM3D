#include "slim/assets/Manager.hpp"
#include "slim/debug/assert.hpp"
#include "slim/io/macros.h"

namespace slim
{
namespace assets
{

Manager
Manager::instance;


Manager::Manager()
{
}

Manager::~Manager()
{
}


bool
Manager::onInit()
{
    return true;
}

void
Manager::onDestroy()
{
}

void
Manager::setExecutablePath(const char* path)
{
    SLIM_DEBUG_ASSERT(m_path.isEmpty()); // This function is supposed to be called only once.
    m_path << path << SLIM_IO_SEPARATOR_CHAR << SLIM_ASSETS_FOLDER << SLIM_IO_SEPARATOR_CHAR;
}

}
}
