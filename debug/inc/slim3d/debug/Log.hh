//
// Log.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:13:49 2015 Aracthor
// Last Update Mon Aug 31 23:44:35 2015 Aracthor
//

#ifndef SLIM3D_DEBUG_LOG_HH_
# define SLIM3D_DEBUG_LOG_HH_

namespace slim
{
namespace debug
{

class	Log
{
public:
    Log();
    ~Log();

public:
    void	init();
    void	destroy();
};

}
}

#endif // !SLIM3D_DEBUG_LOG_HH_
