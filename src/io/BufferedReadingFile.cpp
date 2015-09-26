#include "slim/debug/SyscallException.hh"
#include "slim/io/BufferedReadingFile.hh"

namespace slim
{
namespace io
{

BufferedReadingFile::BufferedReadingFile(const char* name) :
    ReadingFile(name)
{
    SLIM_DEBUG_SYSCALL_CALL_PTR(m_stream = fopen(name, "r"));
}

BufferedReadingFile::~BufferedReadingFile()
{
}


size_t
BufferedReadingFile::read(void* buffer, size_t size)
{
    size_t	extracted = fread(buffer, 1, size, m_stream);

    if (ferror(m_stream))
    {
	this->onError("Buffered mode, reading from");
    }

    return extracted;
}

}
}
