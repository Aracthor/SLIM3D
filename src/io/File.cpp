#include "slim/io/File.hh"
#include "slim/io/FileException.hh"

#include <cstdio>

namespace slim
{
namespace io
{

File::File(const char* name) :
    m_name(name),
    m_infos(name)
{
}

File::~File() noexcept(false)
{
}


void
File::onError(const char* message) const
{
    char	buffer[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

    snprintf(buffer, SLIM_DEBUG_MESSAGE_BUFFER_SIZE, "%s %s.", message, m_name);
    throw FileException(m_name, buffer, __FILE__, __func__, __LINE__);
}

}
}
