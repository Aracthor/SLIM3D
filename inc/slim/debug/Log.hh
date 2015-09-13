#ifndef SLIM_DEBUG_LOG_HH_
# define SLIM_DEBUG_LOG_HH_

# include "slim/core/system.h"
# include "slim/debug/LogStream.hh"
# include "slim/resources/Directory.hh"
# include "slim/time/Date.hh"

# define SLIM_DEBUG_LOG_NAME_BUFFER_SIZE	0x100
# define SLIM_DEBUG_LOG_LEVELS_NUMBER		4

namespace slim
{
namespace debug
{

class	LogBase
{
public:
    LogBase(const char* name);
    virtual ~LogBase();

public:
    virtual void	init(resources::Directory& directory) = 0;
    virtual void	destroy() = 0;

public:
    inline void		setConsoleOutputLevel(char level);
    inline void		setFileOutputLevel(char level);

public:
    virtual void	write(const char* line, unsigned int size) = 0;

public:
    LogStream		log;
    LogStream		info;
    LogStream		warning;
    LogStream		error;

protected:
    const char*		m_name;
    unsigned int	m_consoleOutputLevel;
    unsigned int	m_fileOutputLevel;

private:
    void	manageActivations();
};

}
}

# include "Log.hpp"

# if IS_COMPUTER(SLIM_CORE_SYSTEM)
#  include "Log/ConsoleLog.hh"
# else
#  error "Log class not created for this system."
# endif

#endif // !SLIM_DEBUG_LOG_HH_
