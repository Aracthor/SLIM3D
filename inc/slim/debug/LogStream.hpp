#ifndef SLIM_DEBUG_LOG_STREAM_HPP_
# define SLIM_DEBUG_LOG_STREAM_HPP_

# include "slim/containers/Buffer.hpp"
# include "slim/system.h"

# define SLIM_DEBUG_ELEMENT_BUFFER_SIZE		0x200

# define SLIM_DEBUG_LOG_LEVEL			0
# define SLIM_DEBUG_INFO_LEVEL			1
# define SLIM_DEBUG_WARNING_LEVEL		2
# define SLIM_DEBUG_ERROR_LEVEL			3

namespace slim
{
namespace debug
{

class	Log;

class	LogStream
{
public:
    enum	ESpecialData {endline};

private:
    static const char*	s_levels[4];

public:
    LogStream(Log* log, const char* name, unsigned int level);
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
    Log*		m_log;
    const char*		m_name;
    unsigned int	m_level;
    bool		m_active;
    containers::Buffer<char, SLIM_DEBUG_ELEMENT_BUFFER_SIZE>	m_buffer;
};

}
}

# include "LogStream.ipp"

#endif // !SLIM_DEBUG_LOG_STREAM_HPP_
