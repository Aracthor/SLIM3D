#ifndef SLIM_RESOURCES_DIRECTORY_HH_
# define SLIM_RESOURCES_DIRECTORY_HH_

# include "slim/resources/BufferedReadingFile.hh"
# include "slim/resources/BufferedWritingFile.hh"
# include "slim/resources/UnbufferedReadingFile.hh"
# include "slim/resources/UnbufferedWritingFile.hh"

# include <cstring>
# include <sys/types.h>

# define SLIM_RESOURCES_MAX_PATH_LENGTH		0x1000
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
};

# include "Directory.hpp"

}
}

#endif // !SLIM_RESOURCES_DIRECTORY_HH_
