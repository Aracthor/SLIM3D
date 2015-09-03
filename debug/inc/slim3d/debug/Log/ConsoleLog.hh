//
// ConsoleLog.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Tue Sep  1 23:36:18 2015 Aracthor
// Last Update Thu Sep  3 22:54:21 2015 Aracthor
//

#include "slim3d/resources/IWritingFile.hh"

namespace slim
{
namespace debug
{

class		Log : public LogBase
{
public:
    Log(const char* name);
    ~Log();

public:
    void	init(resources::Directory& directory);
    void	destroy();

protected:
    void	write(const char* message, int level);

private:
    resources::IWritingFile*	m_file;
};

}
}
