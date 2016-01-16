#ifndef SLIM_DEBUG_LOG_HPP_
# define SLIM_DEBUG_LOG_HPP_

# include "slim/system.h"
# include "slim/debug/LogStream.hpp"
# include "slim/io/Directory.hpp"
# include "slim/time/Date.hpp"

# define SLIM_DEBUG_CONSOLE_LOG_BUFFER_SIZE	0x200
# define SLIM_DEBUG_LOG_NAME_BUFFER_SIZE	0x200
# define SLIM_DEBUG_LOG_LEVELS_NUMBER		4

namespace slim
{
namespace debug
{

class	Log
{
public:
    Log(const char* name);
    virtual ~Log();

public:
    void	init(io::Directory& directory);
    void	destroy();

public:
    inline void	setConsoleOutputLevel(char level);
    inline void	setFileOutputLevel(char level);

public:
    void	write(const char* line, unsigned int size, unsigned int level);

public:
    LogStream		log;
    LogStream		info;
    LogStream		warning;
    LogStream		error;

private:
    void		manageActivations();

private:
    const char*		m_name;
    unsigned int	m_consoleOutputLevel;
    unsigned int	m_fileOutputLevel;
    io::WritingFile*	m_file;
    char		m_fileBuffer[SLIM_DEBUG_CONSOLE_LOG_BUFFER_SIZE];
};

}
}

# include "Log.ipp"

#endif // !SLIM_DEBUG_LOG_HPP_
