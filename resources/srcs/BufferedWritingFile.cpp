//
// BufferedWritingFile.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:50:16 2015 Aracthor
// Last Update Wed Sep  2 17:07:49 2015 Aracthor
//

#include "slim3d/resources/BufferedWritingFile.hh"

BufferedWritingFile::BufferedWritingFile(const char* name) :
    BufferedFile(name)
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
    if (fwrite(data, size, 1, m_stream) != size)
    {
	this->onError("Buffered mode, error writing in");
    }

    return (size);
}
