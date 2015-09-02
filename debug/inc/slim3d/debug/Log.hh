//
// Log.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:13:49 2015 Aracthor
// Last Update Wed Sep  2 09:13:03 2015 Aracthor
//

#ifndef SLIM3D_DEBUG_LOG_HH_
# define SLIM3D_DEBUG_LOG_HH_

# include "slim3d/core/system.h"

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
    virtual void	init() = 0;
    virtual void	destroy() = 0;

public:
    inline void	setConsoleOutputLevel(char level);
    inline void	setFileOutputLevel(char level);
    template <typename T>
    void	writeLog(const T& elem);
    template <typename T>
    void	writeInfo(const T& elem);
    template <typename T>
    void	writeWarning(const T& elem);
    template <typename T>
    void	writeError(const T& elem);

protected:
    virtual void	write(const char* message, int level) = 0;

protected:
    const char*	m_name;
    char	m_consoleOutputLevel;
    char	m_fileOutputLevel;
};

# include "Log.hpp"

}
}

# if IS_COMPUTER(SLIM3D_CORE_SYSTEM)
#  include "Log/ConsoleLog.hh"
# else
#  error "Log class not created for this system."
# endif

#endif // !SLIM3D_DEBUG_LOG_HH_
