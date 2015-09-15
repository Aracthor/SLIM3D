#include <sys/stat.h>
#include <sys/types.h>
#include <Windows.h>

#include "slim/debug/WindowsException.hh"

namespace slim
{
namespace resources
{

UnbufferedWritingFile::UnbufferedWritingFile(const char* name) :
    UnbufferedFile(name)
{
    m_fd = CreateFile(name, 0644, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (m_fd == INVALID_HANDLE_VALUE)
    {
	debug::WindowsException::throws(__FILE__, __func__, __LINE__);
    }
}

UnbufferedWritingFile::~UnbufferedWritingFile()
{
}


size_t
UnbufferedWritingFile::write(const void* data, size_t size)
{
    DWORD	wrote;
    
    if (WriteFile(m_fd, data, size, &wrote, nullptr) == FALSE)
    {
	debug::WindowsException::throws(__FILE__, __func__, __LINE__);
    }

    return (wrote);
}

}
}
