//
// Date.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/time
// 
// Made by Aracthor
// 
// Started on  Thu Sep  3 22:22:11 2015 Aracthor
// Last Update Thu Sep  3 22:43:04 2015 Aracthor
//

#ifndef SLIM3D_TIME_DATE_HH_
# define SLIM3D_TIME_DATE_HH_

# include <ctime>

namespace slim
{
namespace time
{

class	Date
{
public:
    Date(time_t seconds = ::time(NULL), bool local = true);
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

# include "Date.hpp"

}
}

#endif // !SLIM3D_TIME_DATE_HH_