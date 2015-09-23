#include "slim/resources/BufferedReadingFile.hh"

namespace slim
{
namespace resources
{

BufferedReadingFile::BufferedReadingFile(const char* name) :
    ReadingFile(name)
{
    m_stream = fopen(name, "r");
    if (m_stream == NULL)
    {
	this->onError("Buffered mode, cannot open file");
    }
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
