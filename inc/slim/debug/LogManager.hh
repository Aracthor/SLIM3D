//
// LogManager.hh for SLIM in /home/aracthor/programs/projects/SLIM/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:04:38 2015 Aracthor
// Last Update Wed Sep  2 17:42:20 2015 Aracthor
//

#ifndef SLIM_DEBUG_LOG_MANAGER_HH_
# define SLIM_DEBUG_LOG_MANAGER_HH_

# include "slim/core/Singleton.hh"
# include "slim/debug/Log.hh"

# define SLIM_DEBUG_LOGS_NUMBER	1

namespace slim
{
namespace debug
{

class		LogManager : public core::Singleton
{
public:
    static LogManager	instance;

public:
    LogManager();
    ~LogManager();

public:
    void	init();
    void	destroy();

private:
    Log		m_logs[SLIM_DEBUG_LOGS_NUMBER];

public:
    Log&	resources;
};

}
}

#endif // !SLIM_DEBUG_LOG_MANAGER_HH_
