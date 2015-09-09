//
// Exception.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 18:03:15 2015 Aracthor
// Last Update Thu Sep 10 00:02:48 2015 Aracthor
//

#ifndef SLIM3D_DEBUG_EXCEPTION_HH_
# define SLIM3D_DEBUG_EXCEPTION_HH_

# include <exception>

# define SLIM3D_DEBUG_MESSAGE_BUFFER_SIZE	0x1000

namespace slim
{
namespace debug
{

class	Exception : public std::exception
{
public:
    Exception(const char* message, const char* file, const char* function, int line);
    virtual ~Exception() throw();

public:
    virtual const char*	what() const throw();
    inline const char*	getProblem() const throw();
    inline const char*	getFile() const throw();
    inline const char*	getFunction() const throw();
    inline int		getLine() const throw();

protected:
    char	m_whatMessage[SLIM3D_DEBUG_MESSAGE_BUFFER_SIZE];
    const char*	m_problem;
    const char*	m_file;
    const char*	m_function;
    const int	m_line;
};

}
}

# include "Exception.hpp"

#endif // !SLIM3D_DEBUG_EXCEPTION_HH_
