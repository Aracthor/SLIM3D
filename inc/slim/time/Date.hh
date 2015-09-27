#ifndef SLIM_TIME_DATE_HH_
# define SLIM_TIME_DATE_HH_

# include <ctime>

namespace slim
{
namespace time
{

class	Date
{
public:
    Date(time_t seconds = ::time(nullptr), bool local = true);
    ~Date();

public:
    void	setSeconds(time_t seconds);

public:
    inline bool		isLocal() const;
    inline time_t	getUnixSeconds() const;
    inline void		toFormat(char* buffer, size_t size, const char* format) const;

private:
    bool	m_local;
    time_t	m_seconds;
    struct tm*	m_completeTime;
};

}
}

# include "Date.hpp"

#endif // !SLIM_TIME_DATE_HH_
