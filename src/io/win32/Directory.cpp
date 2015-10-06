#include "slim/debug/WindowsException.hpp"
#include "slim/io/FileException.hpp"
#include "slim/io/macros.h"

#include <cerrno>
#include <io.h>
#include <Windows.h>

namespace slim
{
namespace io
{

Directory::Directory(const char* path, bool completePath)
{
    if (completePath)
    {
	strcpy(m_path, path);
    }
    else
    {
	size_t	size;

	if (GetCurrentDirectory(SLIM_IO_MAX_PATH_LENGTH - strlen(path) - 2, m_path) == 0)
	{
	    debug::WindowsException::throws(__FILE__, __func__, __LINE__);
	}

	size = strlen(m_path);
	m_path[size] = SLIM_IO_SEPARATOR_CHAR;
	m_path[size + 1] = '\0';
	strcat(m_path, path);
	size = strlen(m_path);
	m_path[size] = SLIM_IO_SEPARATOR_CHAR;
	m_path[size + 1] = '\0';
	m_pathSize = size + 1;
    }

    this->openDirectory();
}

Directory::~Directory()
{
}


void
Directory::openDirectory()
{
    int	errno_value = _access_s(m_path, 00);

    if (errno_value != 0 && errno != ENOENT)
    {
	throw FileException(m_path, "Cannot check directory creation", __FILE__, __func__, __LINE__);
    }
    else if (errno_value == ENOENT)
    {
	SLIM_DEBUG_WINDOWS_SYSCALL_CALL(CreateDirectory(m_path, nullptr));
    }
}

}
}
