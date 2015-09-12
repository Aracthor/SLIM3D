//
// BufferedReadingFile.hh for SLIM in /home/aracthor/programs/projects/SLIM/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:44:14 2015 Aracthor
// Last Update Wed Sep  2 15:42:42 2015 Aracthor
//

#ifndef SLIM_RESOURCES_BUFFERED_READING_FILE_HH_
# define SLIM_RESOURCES_BUFFERED_READING_FILE_HH_

# include "slim/resources/BufferedFile.hh"
# include "slim/resources/IReadingFile.hh"

namespace slim
{
namespace resources
{

class	BufferedReadingFile : public BufferedFile,
			      public IReadingFile
{
public:
    BufferedReadingFile(const char* name);
    virtual ~BufferedReadingFile();

public:
    size_t	read(void* buffer, size_t size);
};

}
}

#endif // !SLIM_RESOURCES_BUFFERED_READING_FILE_HH_
