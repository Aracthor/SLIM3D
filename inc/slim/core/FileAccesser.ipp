#include "slim/debug/assert.hpp"
#include "slim/io/macros.h"

namespace slim
{
namespace core
{

void
FileAccesser::setExecutablePath(const char* path)
{
    SLIM_DEBUG_ASSERT(m_path.isEmpty()); // This function is supposed to be called only once.
    m_path << path << SLIM_IO_SEPARATOR_CHAR << ".." << SLIM_IO_SEPARATOR_CHAR << m_folder << SLIM_IO_SEPARATOR_CHAR;
}

}
}
