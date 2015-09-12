//
// IWritingFile.hh for SLIM in /home/aracthor/programs/projects/SLIM/resources
// 
// Made by Aracthor
// 
// Started on  Thu Sep  3 20:34:26 2015 Aracthor
// Last Update Thu Sep  3 20:37:32 2015 Aracthor
//

#ifndef SLIM_RESOURCES_IWRITING_FILE_HH_
# define SLIM_RESOURCES_IWRITING_FILE_HH_

namespace slim
{
namespace resources
{

class	IWritingFile
{
public:
    virtual ~IWritingFile() {}

public:
    virtual size_t	write(const void* data, size_t size) = 0;
};

}
}

#endif // !SLIM_RESOURCES_IWRITING_FILE_HH_
