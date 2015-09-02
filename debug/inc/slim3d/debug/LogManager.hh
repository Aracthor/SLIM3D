//
// LogManager.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:04:38 2015 Aracthor
// Last Update Tue Sep  1 23:05:44 2015 Aracthor
//

#ifndef SLIM3D_DEBUG_LOG_MANAGER_HH_
# define SLIM3D_DEBUG_LOG_MANAGER_HH_

# include "slim3d/core/Singleton.hh"
# include "slim3d/debug/Log.hh"

# define SLIM3D_DEBUG_LOGS_NUMBER	1

namespace slim
{
namespace debug
{

class		LogManager : public core::Singleton
{
public:
    static LogManager	instance;

public:
    void	init();
    void	destroy();

private:
    Log		m_logs[SLIM3D_DEBUG_LOGS_NUMBER];
};

}
}

#endif // !SLIM3D_DEBUG_LOG_MANAGER_HH_
