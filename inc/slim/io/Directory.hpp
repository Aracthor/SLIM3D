#ifndef SLIM_IO_DIRECTORY_HH_
# define SLIM_IO_DIRECTORY_HH_

# include "slim/io/BufferedReadingFile.hpp"
# include "slim/io/BufferedWritingFile.hpp"

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
    template <class T> // T must inherit from slim::io::File
    T*	newFile(const char* fileName);

public:
    inline const char*	getPath() const;

private:
    void	openDirectory();

private:
    char	m_path[SLIM_IO_MAX_PATH_LENGTH];
    size_t	m_pathSize;
};

# include "Directory.ipp"

}
}

#endif // !SLIM_IO_DIRECTORY_HH_
