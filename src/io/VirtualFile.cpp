#include "slim/attributes.h"
#include "slim/debug/assert.hpp"
#include "slim/io/VirtualFile.hpp"
#include "slim/io/BufferedReadingFile.hpp"
#include "slim/memory/Manager.hpp"

#include "slim/string.h"

namespace slim
{
namespace io
{

memory::ArenaChunk&
VirtualFile::getMemoryChunk()
{
    if (!s_memory.isInited())
    {
	s_memory.init(memory::Manager::instance.createChunk<memory::ArenaChunk>(SLIM_IO_VIRTUAL_FILE_MAX_SIZE,
										"Virtual file"));
    }
    return s_memory.getData();
}

containers::SingleWrap<memory::ArenaChunk>
VirtualFile::s_memory;


VirtualFile
VirtualFile::fromRealFile(const char* fileName)
{
    BufferedReadingFile	file(fileName);

    return VirtualFile::fromRealFile(file);
}

VirtualFile
VirtualFile::fromRealFile(ReadingFile& file)
{
    unsigned int	size = 0;
    unsigned char*	data = new unsigned char[file.getInfos().getSize()];
    unsigned int	bufferSize;
    unsigned char	buffer[SLIM_IO_FILE_READ_BUFFER_SIZE];

    do
    {
	bufferSize = file.read(buffer, SLIM_IO_FILE_READ_BUFFER_SIZE);
	memcpy(&data[size], buffer, bufferSize);
	size += bufferSize;
    }
    while (bufferSize > 0);

    return VirtualFile(data, size, file.getName());
}


VirtualFile::VirtualFile(unsigned char* data, unsigned int size, const char* name) :
    m_data(data),
    m_size(size),
    m_name(name)
{
}

VirtualFile::VirtualFile(const VirtualFile& reference) :
    m_size(reference.getSize()),
    m_name(reference.getName())
{
    m_data = new unsigned char[m_size];
    memcpy(m_data, reference.m_data, m_size);
}

VirtualFile::~VirtualFile()
{
    delete[] m_data;
}


void
VirtualFile::toBuffer(char* buffer, unsigned int size) const
{
    SLIM_CORE_USE(size);
    SLIM_DEBUG_ASSERT(size > m_size);
    memcpy(buffer, m_data, m_size);
    buffer[m_size] = '\0';
}


void
VirtualFile::read(unsigned char* buffer, unsigned int size)
{
    SLIM_DEBUG_ASSERT(m_index + size <= m_size);
    memcpy(buffer, &m_data[m_index], size);
    m_index += size;
}


const char*
VirtualFile::getExtention() const
{
    const char*	ptr = strrchr(m_name, '.');

    if (ptr == nullptr)
    {
	return "";
    }
    else
    {
	return (ptr + 1);
    }
}

}
}
