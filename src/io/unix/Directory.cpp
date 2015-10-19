#include "slim/debug/syscall.hpp"
#include "slim/io/macros.h"

#include <cerrno>
#include <sys/stat.h>
#include <unistd.h>

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

	if (getcwd(m_path, SLIM_IO_MAX_PATH_LENGTH - strlen(path) - 2) == nullptr)
	{
	    SLIM_DEBUG_EXIT("Cannot open ", path, " directory because of cwd recovery");
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
    int	accessCheck = access(m_path, F_OK);

    if (accessCheck == -1 && errno != ENOENT)
    {
	SLIM_DEBUG_EXIT("Cannot check existence of ", m_path, ": ", strerror(errno));
    }
    else if (errno == ENOENT)
    {
	SLIM_DEBUG_SYSCALL_CALL(mkdir(m_path, SLIM_IO_DIRECTORY_PERMISSIONS));
    }
}

}
}
