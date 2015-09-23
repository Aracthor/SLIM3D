#include "slim/resources/BufferedWritingFile.hh"
#include <iostream>

namespace slim
{
namespace resources
{

BufferedWritingFile::BufferedWritingFile(const char* name) :
    WritingFile(name)
{
    m_stream = fopen(name, "w");
    if (m_stream == NULL)
    {
	this->onError("Buffered mode, cannot open file");
    }
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
