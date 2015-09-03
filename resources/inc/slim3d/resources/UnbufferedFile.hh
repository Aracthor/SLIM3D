//
// UnbufferedFile.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:22:30 2015 Aracthor
// Last Update Wed Sep  2 14:27:01 2015 Aracthor
//

#ifndef SLIM3D_RESOURCES_UNBUFFERED_FILE_HH_
# define SLIM3D_RESOURCES_UNBUFFERED_FILE_HH_

# include "slim3d/resources/File.hh"

# include <unistd.h>

namespace slim
{
namespace resources
{

class	UnbufferedFile : public File
{
public:
    UnbufferedFile(const char* name);
    virtual ~UnbufferedFile();

protected:
    int	m_fd;
};

}
}

#endif // !SLIM3D_RESOURCES_UNBUFFERED_FILE_HH_
