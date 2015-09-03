//
// UnbufferedReadingFile.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:44:14 2015 Aracthor
// Last Update Wed Sep  2 15:42:52 2015 Aracthor
//

#ifndef SLIM3D_RESOURCES_UNBUFFERED_READING_FILE_HH_
# define SLIM3D_RESOURCES_UNBUFFERED_READING_FILE_HH_

# include "slim3d/resources/UnbufferedFile.hh"
# include "slim3d/resources/IReadingFile.hh"

namespace slim
{
namespace resources
{

class	UnbufferedReadingFile : public UnbufferedFile,
				public IReadingFile
{
public:
    UnbufferedReadingFile(const char* name);
    virtual ~UnbufferedReadingFile();

public:
    size_t	read(void* buffer, size_t size);
};

}
}

#endif // !SLIM3D_RESOURCES_UNBUFFERED_READING_FILE_HH_
