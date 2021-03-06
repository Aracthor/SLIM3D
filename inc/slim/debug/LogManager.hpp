#ifndef SLIM_DEBUG_LOG_MANAGER_HPP_
# define SLIM_DEBUG_LOG_MANAGER_HPP_

# include "slim/core/FileAccesser.hpp"
# include "slim/core/Singleton.hpp"
# include "slim/debug/Log.hpp"

# define SLIM_DEBUG_LOGS_FOLDER	"logs"
# define SLIM_DEBUG_LOGS_NUMBER	3

namespace slim
{
namespace debug
{

class		LogManager : public core::Singleton,
			     public core::FileAccesser
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
    Log&	memory;
};

}
}

#endif // !SLIM_DEBUG_LOG_MANAGER_HPP_
