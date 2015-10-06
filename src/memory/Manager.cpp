#include "slim/memory/Manager.hpp"

#include <cstdlib>

namespace slim
{
namespace memory
{

const std::size_t
Manager::size = SLIM_MEMORY_TOTAL_SIZE;

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
    m_memory = static_cast<char*>(malloc(Manager::size));

    return (m_memory == nullptr);
}

void
Manager::onDestroy()
{
    free(m_memory);
}

}
}
