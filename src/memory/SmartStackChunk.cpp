#include "slim/debug/exit.hpp"
#include "slim/memory/SmartStackChunk.hpp"

namespace slim
{
namespace memory
{

SmartStackChunk::SmartStackChunk(char* data, std::size_t size, const char* name) :
    Chunk(data, size, name)
{
    Header*	header = reinterpret_cast<Header*>(m_start);

    header->previous = nullptr;

    m_data += sizeof(Header);
    m_size += sizeof(Header);
}

SmartStackChunk::~SmartStackChunk()
{
}


void*
SmartStackChunk::alloc(std::size_t size)
{
    char*	ptr = m_data + sizeof(Header);
    Header*	header = reinterpret_cast<Header*>(m_data);

    if (m_maxSize - m_size < size + sizeof(Header))
    {
	SLIM_DEBUG_EXIT("Memory overflow in smart stack chunk \"", m_name, "\".");
    }

    header->free = false;
    header->size = size;
    header->previous = m_lastElem;
    m_lastElem = header;

    m_data += size + sizeof(Header);
    m_size += size + sizeof(Header);

    return ptr;
}

void
SmartStackChunk::free(char* ptr)
{
    Header*	header = reinterpret_cast<Header*>(ptr - sizeof(Header));

    header->free = true;
    if (header == m_lastElem)
    {
	while (header->previous != nullptr && header->free)
	{
	    header = header->previous;
	}

	m_lastElem = header;
	m_data = reinterpret_cast<char*>(header) + sizeof(Header) + header->size;
	m_size = static_cast<std::size_t>(m_start - m_data);
    }
}

}
}
