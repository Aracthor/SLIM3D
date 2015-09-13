#ifndef SLIM_DEBUG_LOG_HH_
# define SLIM_DEBUG_LOG_HH_

# include "slim/core/system.h"
# include "slim/debug/Dumper.hh"
# include "slim/resources/Directory.hh"
# include "slim/time/Date.hh"

# define SLIM_DEBUG_LOG_NAME_BUFFER_SIZE	0x1000
# define SLIM_DEBUG_ELEMENT_BUFFER_SIZE	0x200
# define SLIM_DEBUG_LOG_LEVELS_NUMBER		4

namespace slim
{
namespace debug
{

class	LogBase
{
protected:
    static const char*	s_levels[4];

public:
    LogBase(const char* name);
    virtual ~LogBase();

public:
    virtual void	init(resources::Directory& directory) = 0;
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

    inline void	writeLog(const char* message);
    inline void	writeInfo(const char* message);
    inline void	writeWarning(const char* message);
    inline void	writeError(const char* message);

protected:
    virtual void	write(const char* message, unsigned int level) = 0;
    template <typename T>
    void		writeObject(const T& object, unsigned int level);

protected:
    const char*		m_name;
    unsigned int	m_consoleOutputLevel;
    unsigned int	m_fileOutputLevel;
    Dumper		m_dumper;
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
