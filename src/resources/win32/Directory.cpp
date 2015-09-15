#include "slim/debug/WindowsException.hh"
#include "slim/resources/FileException.hh"
#include "slim/resources/maccros.h"

#include <cerrno>
#include <io.h>
#include <Windows.h>

namespace slim
{
namespace resources
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

	if (GetCurrentDirectory(SLIM_RESOURCES_MAX_PATH_LENGTH - strlen(path) - 2, m_path) == 0)
	{
	    debug::WindowsException::throws(__FILE__, __func__, __LINE__);
	}

	size = strlen(m_path);
	m_path[size] = SLIM_RESOURCES_SEPARATOR_CHAR;
	m_path[size + 1] = '\0';
	strcat(m_path, path);
	size = strlen(m_path);
	m_path[size] = SLIM_RESOURCES_SEPARATOR_CHAR;
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
    int	accessCheck = _access_s(m_path, 00);

    if (accessCheck == -1 && errno != ENOENT)
    {
	throw FileException(m_path, strerror(errno), __FILE__, __func__, __LINE__);
    }
    else if (errno == ENOENT)
    {
	SLIM_DEBUG_SYSCALL_CALL(mkdir(m_path, SLIM_RESOURCES_DIRECTORY_PERMISSIONS));
    }
}

}
}
