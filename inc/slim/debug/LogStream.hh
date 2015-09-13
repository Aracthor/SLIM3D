#ifndef SLIM_DEBUG_LOG_STREAM_HH_
# define SLIM_DEBUG_LOG_STREAM_HH_

# include "slim/containers/Buffer.hh"
# include "slim/core/system.h"

# define SLIM_DEBUG_ELEMENT_BUFFER_SIZE		0x200

namespace slim
{
namespace debug
{

class	LogBase;

class	LogStream
{
public:
    enum	ESpecialData {endline};

private:
    static const char*	s_levels[4];

public:
    LogStream(LogBase* log, const char* name, unsigned int level);
    ~LogStream();

public:
    inline void	setActive(bool active);

public:
    template <typename T>
    LogStream&	operator<<(const T& object);
    LogStream&	operator<<(ESpecialData data);

private:
    void	prepareNextLine();

private:
    LogBase*		m_log;
    const char*		m_name;
    unsigned int	m_level;
    bool	        m_active;
    containers::Buffer<char, SLIM_DEBUG_ELEMENT_BUFFER_SIZE>	m_buffer;
};

}
}

# include "LogStream.hpp"

#endif // !SLIM_DEBUG_LOG_STREAM_HH_
