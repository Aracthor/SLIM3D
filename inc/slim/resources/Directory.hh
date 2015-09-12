//
// Directory.hh for SLIM in /home/aracthor/programs/projects/SLIM/resources
// 
// Made by Aracthor
// 
// Started on  Thu Sep  3 20:40:22 2015 Aracthor
// Last Update Thu Sep  3 21:56:42 2015 Aracthor
//

#ifndef SLIM_RESOURCES_DIRECTORY_HH_
# define SLIM_RESOURCES_DIRECTORY_HH_

# include "slim/resources/BufferedReadingFile.hh"
# include "slim/resources/BufferedWritingFile.hh"
# include "slim/resources/UnbufferedReadingFile.hh"
# include "slim/resources/UnbufferedWritingFile.hh"

# include <cstring>
# include <dirent.h>
# include <sys/types.h>

# define SLIM_RESOURCES_MAX_PATH_LENGTH	0x1000
# define SLIM_RESOURCES_DIRECTORY_PERMISSIONS	0755

namespace slim
{
namespace resources
{

class	Directory
{
public:
    Directory(const char* name, bool completePath = false);
    virtual ~Directory();

public:
    template <class T>
    T*	newFile(const char* fileName);

public:
    inline const char*	getPath() const;

private:
    void	openDirectory();

private:
    char	m_path[SLIM_RESOURCES_MAX_PATH_LENGTH];
    size_t	m_pathSize;
    DIR*	m_dir;
};

# include "Directory.hpp"

}
}

#endif // !SLIM_RESOURCES_DIRECTORY_HH_
