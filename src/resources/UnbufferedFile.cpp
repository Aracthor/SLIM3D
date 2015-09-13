#include "slim/resources/UnbufferedFile.hh"

namespace slim
{
namespace resources
{

UnbufferedFile::UnbufferedFile(const char* name) :
    File(name)
{
}

UnbufferedFile::~UnbufferedFile()
{
    SLIM_DEBUG_SYSCALL_CALL(close(m_fd));
}

}
}
