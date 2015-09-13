#ifndef SLIM_DEBUG_LOG_HH_
# define SLIM_DEBUG_LOG_HH_

# include "slim/containers/Buffer.hh"
# include "slim/core/system.h"
# include "slim/resources/Directory.hh"
# include "slim/time/Date.hh"

# define SLIM_DEBUG_LOG_NAME_BUFFER_SIZE	0x100
# define SLIM_DEBUG_ELEMENT_BUFFER_SIZE		0x200
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
    virtual void	flush(unsigned int level) = 0;
    template <typename T>
    void		write(const T& object, unsigned int level);

protected:
    const char*		m_name;
    unsigned int	m_consoleOutputLevel;
    unsigned int	m_fileOutputLevel;
    containers::Buffer<char, SLIM_DEBUG_ELEMENT_BUFFER_SIZE>	m_buffer;
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
