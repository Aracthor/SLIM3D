#include "slim/resources/VirtualFile.hh"
#include "slim/resources/BufferedReadingFile.hh"

#include <cstring>

namespace slim
{
namespace resources
{

VirtualFile*
VirtualFile::fromRealFile(const char* fileName)
{
    BufferedReadingFile	file(fileName);
    unsigned int	size = 0;
    byte*	        data = new byte[file.getInfos().getSize()];
    unsigned int	bufferSize;
    byte		buffer[SLIM_RESOURCES_FILE_READ_BUFFER_SIZE];

    do
    {
	bufferSize = file.read(buffer, SLIM_RESOURCES_FILE_READ_BUFFER_SIZE);
	memcpy(&data[size], buffer, bufferSize);
	size += bufferSize;
    }
    while (bufferSize > 0);

    return new VirtualFile(data, size);
}


VirtualFile::VirtualFile(byte* data, unsigned int size) :
    m_data(data),
    m_size(size)
{
}

VirtualFile::VirtualFile(const VirtualFile& reference) :
    m_size(reference.getSize())
{
    m_data = new byte[m_size];
    memcpy(m_data, reference.m_data, m_size);
}

VirtualFile::~VirtualFile()
{
    delete[] m_data;
}

}
}
