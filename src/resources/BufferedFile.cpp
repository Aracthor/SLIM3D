//
// BufferedFile.cpp for SLIM in /home/aracthor/programs/projects/SLIM/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:25:04 2015 Aracthor
// Last Update Wed Sep  2 15:02:16 2015 Aracthor
//

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
