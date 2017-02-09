#include "slim/debug/exit.hpp"
#include "slim/io/File.hpp"

namespace slim
{
namespace io
{

File::File(const char* name) :
    m_name(name),
    m_infos(name)
{
}

File::~File()
{
}


void
File::onError(const char* message) const
{
    SLIM_DEBUG_EXIT("Error with file ", m_name, message);
}

}
}
