//
// ConsoleLog.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Tue Sep  1 23:36:18 2015 Aracthor
// Last Update Wed Sep  2 00:18:37 2015 Aracthor
//

#include <cstdio>

namespace slim
{
namespace debug
{

class	Log : public LogBase
{
public:
    Log(const char* name);
    ~Log();

public:
    void	init();
    void	destroy();

protected:
    void	write(const char* message, int level);

private:
    FILE*	m_file;
};

}
}
