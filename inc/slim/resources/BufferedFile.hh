//
// BufferedFile.hh for SLIM in /home/aracthor/programs/projects/SLIM/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:22:30 2015 Aracthor
// Last Update Wed Sep  2 14:24:32 2015 Aracthor
//

#ifndef SLIM_RESOURCES_BUFFERED_FILE_HH_
# define SLIM_RESOURCES_BUFFERED_FILE_HH_

# include "slim/resources/File.hh"

# include <cstdio>

namespace slim
{
namespace resources
{

class	BufferedFile : public File
{
public:
    BufferedFile(const char* name);
    virtual ~BufferedFile();

protected:
    FILE*	m_stream;
};

}
}

#endif // !SLIM_RESOURCES_BUFFERED_FILE_HH_
