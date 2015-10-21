#include "slim/assets/Manager.hpp"

namespace slim
{
namespace assets
{

Manager
Manager::instance;


Manager::Manager() :
    FileAccesser(SLIM_ASSETS_FOLDER)
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

}
}
