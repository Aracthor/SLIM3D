#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

namespace slim
{
namespace io
{

UnbufferedWritingFile::UnbufferedWritingFile(const char* name) :
    WritingFile(name)
{
    m_fd = open(name, O_RDONLY);
    if (m_fd == -1)
    {
	this->onError("Unbuffered mode, cannot open file");
    }
}

UnbufferedWritingFile::~UnbufferedWritingFile() noexcept(false)
{
}


size_t
    UnbufferedWritingFile::write(const void* data, size_t size)
{
    ssize_t	wrote = ::write(m_fd, data, size);

    if (wrote == -1)
    {
	this->onError("Unbuffered mode, error writing in");
    }

    return (wrote);
}

}
}
