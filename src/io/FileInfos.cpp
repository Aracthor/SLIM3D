#include "slim/debug/syscall.hpp"
#include "slim/io/FileInfos.hpp"

namespace slim
{
namespace io
{

FileInfos::FileInfos(const char* name) :
    m_name(name)
{
}

FileInfos::~FileInfos()
{
}


unsigned int
FileInfos::getSize()
{
    this->checkForInitialization();
    return m_stats.st_size;
}


void
FileInfos::checkForInitialization()
{
    if (m_inited == false)
    {
	this->init();
    }
}

void
FileInfos::init()
{
    m_inited = true;
    SLIM_DEBUG_SYSCALL_CALL(::stat(m_name, &m_stats));
}

}
}
