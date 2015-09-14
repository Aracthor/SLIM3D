#include "slim/resources/BufferedFile.hh"

namespace slim
{
namespace resources
{

BufferedFile::BufferedFile(const char* name) :
    File(name)
{
}

BufferedFile::~BufferedFile()
{
    if (fclose(m_stream) != 0)
    {
	this->onError("Cannot close file");
    }
}

}
}
