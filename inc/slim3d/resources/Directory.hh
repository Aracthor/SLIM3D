//
// Directory.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Thu Sep  3 20:40:22 2015 Aracthor
// Last Update Thu Sep  3 21:56:42 2015 Aracthor
//

#ifndef SLIM3D_RESOURCES_DIRECTORY_HH_
# define SLIM3D_RESOURCES_DIRECTORY_HH_

# include "slim3d/resources/BufferedReadingFile.hh"
# include "slim3d/resources/BufferedWritingFile.hh"
# include "slim3d/resources/UnbufferedReadingFile.hh"
# include "slim3d/resources/UnbufferedWritingFile.hh"

# include <cstring>
# include <dirent.h>
# include <sys/types.h>

# define SLIM3D_RESOURCES_MAX_PATH_LENGTH	0x1000
# define SLIM3D_RESOURCES_DIRECTORY_PERMISSIONS	0755

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
    char	m_path[SLIM3D_RESOURCES_MAX_PATH_LENGTH];
    size_t	m_pathSize;
    DIR*	m_dir;
};

# include "Directory.hpp"

}
}

#endif // !SLIM3D_RESOURCES_DIRECTORY_HH_
