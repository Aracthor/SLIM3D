#include "slim/debug/syscall.hpp"
#include "slim/io/BufferedWritingFile.hpp"

namespace slim
{
namespace io
{

BufferedWritingFile::BufferedWritingFile(const char* name) :
    WritingFile(name)
{
    SLIM_DEBUG_SYSCALL_CALL_PTR(m_stream = fopen(name, "w"));
}

BufferedWritingFile::~BufferedWritingFile()
{
}


size_t
BufferedWritingFile::write(const void* data, size_t size)
{
    if (fwrite(data, size, 1, m_stream) != 1)
    {
	this->onError("Buffered mode, error writing in");
    }

    return (size);
}

}
}
