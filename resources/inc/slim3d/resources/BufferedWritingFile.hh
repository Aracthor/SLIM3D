//
// BufferedWritingFile.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:44:14 2015 Aracthor
// Last Update Wed Sep  2 14:48:56 2015 Aracthor
//

#ifndef SLIM3D_RESOURCES_BUFFERED_WRITING_FILE_HH_
# define SLIM3D_RESOURCES_BUFFERED_WRITING_FILE_HH_

# include "slim3d/resources/BufferedFile.hh"
# include "slim3d/resources/IWritingFile.hh"

namespace slim
{
namespace resources
{

class	BufferedWritingFile : public BufferedFile,
			      public IWritingFile
{
public:
    BufferedWritingFile(const char* name);
    virtual ~BufferedWritingFile();

public:
    void	write(const void* data, size_t size);
};

}
}

#endif // !SLIM3D_RESOURCES_BUFFERED_WRITING_FILE_HH_
