#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

namespace slim
{
namespace io
{

UnbufferedReadingFile::UnbufferedReadingFile(const char* name) :
    ReadingFile(name)
{
    m_fd = open(name, O_RDONLY);
    if (m_fd == -1)
    {
	this->onError("Unbuffered mode, cannot open file");
    }
}

UnbufferedReadingFile::~UnbufferedReadingFile() noexcept(false)
{
}


size_t
UnbufferedReadingFile::read(void* buffer, size_t size)
{
    ssize_t extracted = ::read(m_fd, buffer, size);

    if (extracted == -1)
    {
	this->onError("Unbuffered mode, error reading from");
    }

    return (extracted);
}

}
}
