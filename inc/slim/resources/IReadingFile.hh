//
// IReadingFile.hh for SLIM in /home/aracthor/programs/projects/SLIM/resources
// 
// Made by Aracthor
// 
// Started on  Thu Sep  3 20:34:26 2015 Aracthor
// Last Update Thu Sep  3 20:37:27 2015 Aracthor
//

#ifndef SLIM_RESOURCES_IREADING_FILE_HH_
# define SLIM_RESOURCES_IREADING_FILE_HH_

namespace slim
{
namespace resources
{

class	IReadingFile
{
public:
    virtual ~IReadingFile() {}

public:
    virtual size_t	read(void* buffer, size_t size) = 0;
};

}
}

#endif // !SLIM_RESOURCES_IREADING_FILE_HH_
