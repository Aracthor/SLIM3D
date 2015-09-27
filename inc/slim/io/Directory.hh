#ifndef SLIM_IO_DIRECTORY_HH_
# define SLIM_IO_DIRECTORY_HH_

# include "slim/io/BufferedReadingFile.hh"
# include "slim/io/BufferedWritingFile.hh"
# include "slim/io/UnbufferedReadingFile.hh"
# include "slim/io/UnbufferedWritingFile.hh"

# include <cstring>
# include <sys/types.h>

# define SLIM_IO_MAX_PATH_LENGTH		0x1000
# define SLIM_IO_DIRECTORY_PERMISSIONS	0755

namespace slim
{
namespace io
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
    char	m_path[SLIM_IO_MAX_PATH_LENGTH];
    size_t	m_pathSize;
};

# include "Directory.hpp"

}
}

#endif // !SLIM_IO_DIRECTORY_HH_
