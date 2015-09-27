#include "slim/debug/WindowsException.hh"

#include <sys/stat.h>
#include <sys/types.h>
#include <Windows.h>

namespace slim
{
namespace io
{

UnbufferedReadingFile::UnbufferedReadingFile(const char* name) :
    ReadingFile(name)
{
    m_fd = CreateFile(name, 0644, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (m_fd == INVALID_HANDLE_VALUE)
    {
	debug::WindowsException::throws(__FILE__, __func__, __LINE__);
    }
}

UnbufferedReadingFile::~UnbufferedReadingFile() noexcept(false)
{
}


size_t
UnbufferedReadingFile::read(void* buffer, size_t size)
{
    DWORD   extracted;

    if (ReadFile(m_fd, buffer, size, &extracted, nullptr) == FALSE)
    {
	debug::WindowsException::throws(__FILE__, __func__, __LINE__);
    }

    return (extracted);
}

}
}
