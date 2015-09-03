//
// BufferedReadingFile.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:50:16 2015 Aracthor
// Last Update Thu Sep  3 20:37:52 2015 Aracthor
//

#include "slim3d/resources/BufferedReadingFile.hh"

namespace slim
{
namespace resources
{

BufferedReadingFile::BufferedReadingFile(const char* name) :
    BufferedFile(name)
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
    size_t	extracted = fread(buffer, size, 1, m_stream);

    if (extracted != size)
    {
	if (ferror(m_stream))
	{
	    this->onError("Buffered mode, reading from");
	}
    }

    return (extracted);
}

}
}
