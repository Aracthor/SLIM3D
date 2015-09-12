//
// Directory.cpp for SLIM in /home/aracthor/programs/projects/SLIM/resources
// 
// Made by Aracthor
// 
// Started on  Thu Sep  3 20:51:50 2015 Aracthor
// Last Update Thu Sep  3 23:13:17 2015 Aracthor
//

#include "slim/resources/Directory.hh"
#include "slim/resources/FileException.hh"
#include "slim/resources/maccros.h"

#include <cerrno>
#include <sys/stat.h>
#include <unistd.h>

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

	if (getcwd(m_path, SLIM_RESOURCES_MAX_PATH_LENGTH - strlen(path) - 2) == NULL)
	{
	    throw FileException(path, "Cannot open directory because of cwd recovery",
				__FILE__, __func__, __LINE__);
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
    SLIM_DEBUG_SYSCALL_CALL(closedir(m_dir));
}


void
Directory::openDirectory()
{
    int	accessCheck = access(m_path, F_OK);

    if (accessCheck == -1 && errno != ENOENT)
    {
	throw FileException(m_path, "Cannot check directory excistence",
			    __FILE__, __func__, __LINE__);
    }
    else if (errno == ENOENT)
    {
	SLIM_DEBUG_SYSCALL_CALL(mkdir(m_path, SLIM_RESOURCES_DIRECTORY_PERMISSIONS));
    }

    m_dir = opendir(m_path);
    if (m_dir == NULL)
    {
	throw FileException(m_path, "Cannot open directory", __FILE__, __func__, __LINE__);
    }
}

}
}
