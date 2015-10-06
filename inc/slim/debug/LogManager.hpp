#ifndef SLIM_DEBUG_LOG_MANAGER_HH_
# define SLIM_DEBUG_LOG_MANAGER_HH_

# include "slim/core/Singleton.hpp"
# include "slim/debug/Log.hpp"

# define SLIM_DEBUG_LOGS_NUMBER	2

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

protected:
    bool	onInit() override;
    void	onDestroy() override;

private:
    Log		m_logs[SLIM_DEBUG_LOGS_NUMBER];

public:
    Log&	assets;
    Log&	graphics;
};

}
}

#endif // !SLIM_DEBUG_LOG_MANAGER_HH_
