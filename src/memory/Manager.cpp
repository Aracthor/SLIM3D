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
    m_memoryStart = malloc(Manager::size);
    m_memory = static_cast<char*>(m_memoryStart);

    return (m_memoryStart == nullptr);
}

void
Manager::onDestroy()
{
    free(m_memoryStart);
}

}
}
