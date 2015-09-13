#ifndef SLIM_DEBUG_EXCEPTION_HH_
# define SLIM_DEBUG_EXCEPTION_HH_

# include <exception>

# define SLIM_DEBUG_MESSAGE_BUFFER_SIZE	0x1000

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
    char	m_whatMessage[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];
    const char*	m_problem;
    const char*	m_file;
    const char*	m_function;
    const int	m_line;
};

}
}

# include "Exception.hpp"

#endif // !SLIM_DEBUG_EXCEPTION_HH_
